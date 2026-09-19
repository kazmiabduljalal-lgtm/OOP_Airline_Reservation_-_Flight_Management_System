#include <iostream>
#include <fstream>
#include <string>
#include "Airline.h"

using namespace std;


const string FLIGHTS_FILE    = "flights.dat";
const string PASSENGERS_FILE = "passengers.dat";
const string TICKETS_FILE    = "tickets.dat";

//  CONSTRUCTOR - load data
Airline::Airline()
{
    nextTicketId = 1;
    loadFlights();
    loadPassengers();
    loadTickets();
}


void Airline::saveFlights()
{
    ofstream file(FLIGHTS_FILE.c_str());
    if(!file)
    {
        cout << "Warning: Could not save flights data!" << endl;
        return;
    }

    for(int i = 0; i < (int)flights.size(); i++)
    {
        Flight* f = flights[i];

        // Try DomesticFlight
        DomesticFlight* df = dynamic_cast<DomesticFlight*>(f);
        if(df)
        {
            file << "D|" << df->getFlight_No()   << "|"
                         << df->getOrigin()      << "|"
                         << df->getDestination() << "|"
                         << df->getDate()        << "|"
                         << df->getTotal_Seats()  << "|"
                         << df->getAvailable_Seats() << "|"
                         << df->getBaseFare()    << "\n";
            continue;
        }

        // Try InternationalFlight
        InternationalFlight* inf = dynamic_cast<InternationalFlight*>(f);
        if(inf)
        {
            file << "I|" << inf->getFlight_No()      << "|"
                         << inf->getOrigin()         << "|"
                         << inf->getDestination()    << "|"
                         << inf->getDate()           << "|"
                         << inf->getTotal_Seats()     << "|"
                         << inf->getAvailable_Seats() << "|"
                         << inf->getVisaRequired()   << "|"
                         << inf->getInternationalTax()<< "|"
                         << inf->getBaseFare()       << "\n";
            continue;
        }

        // Try CharterFlight
        CharterFlight* cf = dynamic_cast<CharterFlight*>(f);
        if(cf)
        {
            file << "C|" << cf->getFlight_No()       << "|"
                         << cf->getOrigin()          << "|"
                         << cf->getDestination()     << "|"
                         << cf->getDate()            << "|"
                         << cf->getTotal_Seats()      << "|"
                         << cf->getAvailable_Seats()  << "|"
                         << cf->getContractHolder()  << "|"
                         << cf->getCharterFare()     << "\n";
            continue;
        }
    }

    file.close();
}

//  LOAD FLIGHTS
void Airline::loadFlights()
{
    ifstream file(FLIGHTS_FILE.c_str());
    if(!file) return;   // no file yet = first run

    string line;
    while(getline(file, line))
    {
        if(line.empty()) continue;

        // Parse pipe-separated fields
        vector<string> fields;
        string token;
        for(int i = 0; i <= (int)line.size(); i++)
        {
            if(i == (int)line.size() || line[i] == '|')
            {
                fields.push_back(token);
                token = "";
            }
            else
            {
                token += line[i];
            }
        }

        if(fields.size() < 1) continue;
        string type = fields[0];

        if(type == "D" && fields.size() >= 8)
        {
            string fn   = fields[1];
            string org  = fields[2];
            string dest = fields[3];
            string date = fields[4];
            int total   = atoi(fields[5].c_str());
            int avail   = atoi(fields[6].c_str());
            double fare = atof(fields[7].c_str());

            DomesticFlight* df = new DomesticFlight(fn, org, dest, date, total, fare);
            // restore available seats
            int booked = total - avail;
            for(int b = 0; b < booked; b++) df->bookSeat();
            flights.push_back(df);
        }
        else if(type == "I" && fields.size() >= 10)
        {
            string fn   = fields[1];
            string org  = fields[2];
            string dest = fields[3];
            string date = fields[4];
            int total   = atoi(fields[5].c_str());
            int avail   = atoi(fields[6].c_str());
            bool visa   = (fields[7] == "1");
            double tax  = atof(fields[8].c_str());
            double fare = atof(fields[9].c_str());

            InternationalFlight* inf = new InternationalFlight(fn, org, dest, date, total, visa, tax, fare);
            int booked = total - avail;
            for(int b = 0; b < booked; b++) inf->bookSeat();
            flights.push_back(inf);
        }
        else if(type == "C" && fields.size() >= 9)
        {
            string fn     = fields[1];
            string org    = fields[2];
            string dest   = fields[3];
            string date   = fields[4];
            int total     = atoi(fields[5].c_str());
            int avail     = atoi(fields[6].c_str());
            string holder = fields[7];
            double fare   = atof(fields[8].c_str());

            CharterFlight* cf = new CharterFlight(fn, org, dest, date, total, holder, fare);
            int booked = total - avail;
            for(int b = 0; b < booked; b++) cf->bookSeat();
            flights.push_back(cf);
        }
    }

    file.close();
}

//  SAVE PASSENGERS
//  Format: type|id|name

void Airline::savePassengers()
{
    ofstream file(PASSENGERS_FILE.c_str());
    if(!file)
    {
        cout << "Warning: Could not save passengers data!" << endl;
        return;
    }

    for(int i = 0; i < (int)passengers.size(); i++)
    {
        Passenger* p = passengers[i];

        EconomyPassenger* ep = dynamic_cast<EconomyPassenger*>(p);
        if(ep) { file << "E|" << ep->getId() << "|" << ep->getName() << "\n"; continue; }

        BusinessPassenger* bp = dynamic_cast<BusinessPassenger*>(p);
        if(bp) { file << "B|" << bp->getId() << "|" << bp->getName() << "\n"; continue; }

        FirstClassPassenger* fp = dynamic_cast<FirstClassPassenger*>(p);
        if(fp) { file << "F|" << fp->getId() << "|" << fp->getName() << "\n"; continue; }
    }

    file.close();
}

//  LOAD PASSENGERS
void Airline::loadPassengers()
{
    ifstream file(PASSENGERS_FILE.c_str());
    if(!file) return;

    string line;
    while(getline(file, line))
    {
        if(line.empty()) continue;

        vector<string> fields;
        string token;
        for(int i = 0; i <= (int)line.size(); i++)
        {
            if(i == (int)line.size() || line[i] == '|')
            {
                fields.push_back(token);
                token = "";
            }
            else token += line[i];
        }

        if(fields.size() < 3) continue;
        string type = fields[0];
        int id      = atoi(fields[1].c_str());
        string name = fields[2];

        if(type == "E") passengers.push_back(new EconomyPassenger(id, name));
        else if(type == "B") passengers.push_back(new BusinessPassenger(id, name));
        else if(type == "F") passengers.push_back(new FirstClassPassenger(id, name));
    }

    file.close();
}

//  SAVE TICKETS
//  Format: ticketId|flightNo|passengerId|seatNo|farePaid|active
void Airline::saveTickets()
{
    ofstream file(TICKETS_FILE.c_str());
    if(!file)
    {
        cout << "Warning: Could not save tickets data!" << endl;
        return;
    }

    // Save nextTicketId on first line
    file << nextTicketId << "\n";

    for(int i = 0; i < (int)tickets.size(); i++)
    {
        file << tickets[i].getTicket_Id()           << "|"
             << tickets[i].getFlight()->getFlight_No() << "|"
             << tickets[i].getPassenger()->getId()    << "|"
             << tickets[i].getSeat_Number()            << "|"
             << tickets[i].getFare_Paid()              << "|"
             << (tickets[i].isActive() ? 1 : 0)       << "\n";
    }

    file.close();
}


//  LOAD TICKETS

void Airline::loadTickets()
{
    ifstream file(TICKETS_FILE.c_str());
    if(!file) return;

    string line;

    // First line = nextTicketId
    if(getline(file, line) && !line.empty())
        nextTicketId = atoi(line.c_str());

    while(getline(file, line))
    {
        if(line.empty()) continue;

        vector<string> fields;
        string token;
        for(int i = 0; i <= (int)line.size(); i++)
        {
            if(i == (int)line.size() || line[i] == '|')
            {
                fields.push_back(token);
                token = "";
            }
            else token += line[i];
        }

        if(fields.size() < 6) continue;

        int    ticketId   = atoi(fields[0].c_str());
        string flightNo   = fields[1];
        int    passId     = atoi(fields[2].c_str());
        int    seatNo     = atoi(fields[3].c_str());
        double fare       = atof(fields[4].c_str());
        bool   active     = (fields[5] == "1");

        // Find matching flight
        Flight* f = NULL;
        for(int i = 0; i < (int)flights.size(); i++)
        {
            if(flights[i]->getFlight_No() == flightNo)
            {
                f = flights[i];
                break;
            }
        }

        // Find matching passenger
        Passenger* p = NULL;
        for(int i = 0; i < (int)passengers.size(); i++)
        {
            if(passengers[i]->getId() == passId)
            {
                p = passengers[i];
                break;
            }
        }

        if(f == NULL || p == NULL) continue;

        Ticket t(ticketId, f, p, seatNo, fare);
        if(!active) t.cancel();
        tickets.push_back(t);
    }

    file.close();
}

//  ADD FLIGHT
void Airline::addFlight()
{
    int type;

cout << endl;
cout << "*************** ADD FLIGHT ***************" << endl;
cout << endl;

cout << "       1. Domestic Flight" << endl;
cout << "       2. International Flight" << endl;
cout << "       3. Charter Flight" << endl;

cout << endl;
cout << "******************************************" << endl;
cout << "Enter Choice: ";
cin >> type;

    string fn, org, dest, date;
    int seats;

    cout << "Enter Flight Number : ";
    cin >> fn;

    for(int i = 0; i < (int)flights.size(); i++)
    {
        if(flights[i]->getFlight_No() == fn)
        {
            cout << "Error: same number flight already exists!" << endl;
            return;
        }
    }

    cout << " Please enter the origin       : ";
    cin >> org;
    cout << "Enter Date (DD/MM/YYYY): ";
cin.ignore();
getline(cin, date);
    cout << "Enter Destination  : ";
    cin >> dest;
    cout << "Enter Total Number of  Seats  : ";
    cin >> seats;

    if(seats <= 0)
    {
        cout << "Error: Seats must positive." << endl;
        return;
    }

    if(type == 1)
    {
        double fare;
        cout << "Enter Base_Fare (Rs): ";
        cin >> fare;
        flights.push_back(new DomesticFlight(fn, org, dest, date, seats, fare));
        cout << "Domestic Flight Added." << endl;
    }
    else if(type == 2)
    {
        bool visa;
        double tax, fare;
        int visaInput;
        cout << "Visa Required? (1=Yes, 0=No): ";
        cin >> visaInput;
        visa = (visaInput == 1);
        cout << "Enter International Tax RS : ";
        cin >> tax;
        cout << "Enter Base Fare RS : ";
        cin >> fare;
        flights.push_back(new InternationalFlight(fn, org, dest, date, seats, visa, tax, fare));
        cout << "International Flight Added." << endl;
    }
    else if(type == 3)
    {
        string holder;
        double fare;
        cout << "Enter Contract Holder Name : ";
        cin >> holder;
        cout << "Enter Charter Fare Rs : ";
        cin >> fare;
        flights.push_back(new CharterFlight(fn, org, dest, date, seats, holder, fare));
        cout << "Charter Flight Added." << endl;
    }
    else
    {
        cout << "Invalid type!" << endl;
        return;
    }

    saveFlights();
}

 
//  DISPLAY FLIGHTS

void Airline::displayFlights()
{
    if(flights.empty())
    {
        cout << "\nNo flights are not  available yet." << endl;
        return;
    }

    cout << "\n All Flights " << endl;
    for(int i = 0; i < (int)flights.size(); i++)
        flights[i]->display();
}

//  REGISTER PASSENGER
void Airline::registerPassenger()
{
    int type, id;
  string name;

cout << endl;
cout << "*********** REGISTER PASSENGER ***********" << endl;
cout << endl;

cout << "1. Economy Passenger" << endl;
cout << "2. Business Passenger" << endl;
cout << "3. First Class Passenger" << endl;

cout << endl;
cout << "******************************************" << endl;
cout << "Enter Choice: ";
cin >> type;

    cout << "Enter Passenger ID  : ";
    cin >> id;

    for(int i = 0; i < (int)passengers.size(); i++)
    {
        if(passengers[i]->getId() == id)
        {
            cout << "Error: Passenger ID already exists." << endl;
            return;
        }
    }

    cout << "Enter Passenger Name : ";
    cin >> name;

    if(type == 1)
    {
        passengers.push_back(new EconomyPassenger(id, name));
        cout << "Economy Passenger registered." << endl;
    }
    else if(type == 2)
    {
        passengers.push_back(new BusinessPassenger(id, name));
        cout << "Business Passenger registered." << endl;
    }
    else if(type == 3)
    {
        passengers.push_back(new FirstClassPassenger(id, name));
        cout << "First Class Passenger registered." << endl;
    }
    else
    {
        cout << "Invalid type!" << endl;
        return;
    }

    savePassengers();
}


//  DISPLAY PASSENGERS
void Airline::displayPassengers()
{
    if(passengers.empty())
    {
        cout << "\n passengers are not registered." << endl;
        return;
    }

    cout << "\nAll Passengers" << endl;
    for(int i = 0; i < (int)passengers.size(); i++)
        passengers[i]->display();
}


//  BOOK TICKET
void Airline::bookTicket()
{
    if(flights.empty())
    {
        cout << "\n flights are not  available to book." << endl;
        return;
    }

    if(passengers.empty())
    {
        cout << "\n passengers are not registered." << endl;
        return;
    }

    cout << "\n Book Ticket " << endl;

    cout << "Available Flights:" << endl;
    for(int i = 0; i < (int)flights.size(); i++)
    {
        cout << i+1 << ". Flight " << flights[i]->getFlight_No()
             << " (Available Seats: " << flights[i]->getAvailable_Seats() << ")" << endl;
    }

    string flightNo;
    cout << "Enter Flight Number: ";
    cin >> flightNo;

    Flight* selectedFlight = NULL;
    for(int i = 0; i < (int)flights.size(); i++)
    {
        if(flights[i]->getFlight_No() == flightNo)
        {
            selectedFlight = flights[i];
            break;
        }
    }

    if(selectedFlight == NULL)
    {
        FlightNotFoundException ex;
        ex.message();
        return;
    }

    if(selectedFlight->getAvailable_Seats() <= 0)
    {
        FlightFullException ex;
        ex.message();
        return;
    }

    int passId;
    cout << "Enter Passenger ID : ";
    cin >> passId;

    Passenger* selectedPassenger = NULL;
    for(int i = 0; i < (int)passengers.size(); i++)
    {
        if(passengers[i]->getId() == passId)
        {
            selectedPassenger = passengers[i];
            break;
        }
    }

    if(selectedPassenger == NULL)
    {
        PassengerNotFoundException ex;
        ex.message();
        return;
    }

    for(int i = 0; i < (int)tickets.size(); i++)
    {
        if(tickets[i].isActive() &&
           tickets[i].getFlight() == selectedFlight &&
           tickets[i].getPassenger() == selectedPassenger)
        {
            cout << "Error: Passenger already has an active ticket on this flight!" << endl;
            return;
        }
    }

    int seatNo = selectedFlight->getTotal_Seats() - selectedFlight->getAvailable_Seats() + 1;
    double fare = selectedFlight->calculateFare();

    selectedFlight->bookSeat();

    Ticket newTicket(nextTicketId++, selectedFlight, selectedPassenger, seatNo, fare);
    tickets.push_back(newTicket);

    cout << "\nTicket Booked." << endl;
    newTicket.display();

    saveFlights();
    saveTickets();
}


//  CANCEL TICKET

void Airline::cancelTicket()
{
    if(tickets.empty())
    {
        cout << "\nNo tickets to cancel." << endl;
        return;
    }

    cout << "\n Cancel Ticket " << endl;
    cout << "Active Tickets:" << endl;

    bool anyActive = false;
    for(int i = 0; i < (int)tickets.size(); i++)
    {
        if(tickets[i].isActive())
        {
            tickets[i].display();
            anyActive = true;
        }
    }

    if(!anyActive)
    {
        cout << "Active tickets are not found." << endl;
        return;
    }

    int ticketId;
    cout << "\nEnter Ticket ID to Cancel: ";
    cin >> ticketId;

    for(int i = 0; i < (int)tickets.size(); i++)
    {
        if(tickets[i].getTicket_Id() == ticketId && tickets[i].isActive())
        {
            double farePaid    = tickets[i].getFare_Paid();
            double refundPct   = tickets[i].getPassenger()->getRefundPercentage();
            double refundAmount = (farePaid * refundPct) / 100.0;

            tickets[i].getFlight()->cancelSeat();
            tickets[i].cancel();

            cout << "\nTicket cancelled." << endl;
            cout << "Refund Amount: Rs " << refundAmount
                 << " (" << refundPct << "% of Rs " << farePaid << ")" << endl;

            saveFlights();
            saveTickets();
            return;
        }
    }

    InvalidCancellationException ex;
    ex.message();
}


//  DESTRUCTOR

Airline::~Airline()
{
    for(int i = 0; i < (int)flights.size(); i++)
        delete flights[i];

    for(int i = 0; i < (int)passengers.size(); i++)
        delete passengers[i];
}
