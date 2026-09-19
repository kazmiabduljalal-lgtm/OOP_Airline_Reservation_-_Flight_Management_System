#include <iostream>
#include "Ticket.h"

using namespace std;

Ticket::Ticket(int id, Flight* f, Passenger* p, int seat, double fare)
{
    ticket_Id   = id;
    flight     = f;
    passenger  = p;
    seat_Number = seat;
    fare_Paid   = fare;
    active     = true;
}

void Ticket::display() const
{
	cout << " \n *************** " << endl;
    cout << " Ticket Information " << endl;
    cout << " *************** " << endl;
    
    cout << "Ticket ID   : " << ticket_Id << endl;
    cout << "Passenger   : " << passenger->getName() << endl;
    cout << "Flight No   : " << flight->getFlight_No() << endl;
    cout << "Seat Number : " << seat_Number << endl;
    cout << "Fare Paid   : Rs " << fare_Paid << endl;
    
     if (active)
    {
        cout << "Status      : Active" << endl;
    }
    else
    {
        cout << "Status      : Cancelled" << endl;
    }
}
	// getters functions
	
int Ticket::getTicket_Id() const
{
    return ticket_Id;
}

bool Ticket::isActive() const
{
    return active;
}

// Cancel Ticket
void Ticket::cancel()
{
    active = false;
}

Flight* Ticket::getFlight() const
{
    return flight;
}

Passenger* Ticket::getPassenger() const
{
    return passenger;
}

double Ticket::getFare_Paid() const
{
    return fare_Paid;
}

int Ticket::getSeat_Number() const
{
    return seat_Number;
}

// equality operator
bool Ticket::operator==(const Ticket& other) const
{
    return ticket_Id == other.ticket_Id;
}

// Output Operator
ostream& operator<<(ostream& out, const Ticket& t)
{
    out << "Ticket ID: " << t.ticket_Id
        << ", Seat: " << t.seat_Number
        << ", Fare: Rs " << t.fare_Paid;

    return out;
}
