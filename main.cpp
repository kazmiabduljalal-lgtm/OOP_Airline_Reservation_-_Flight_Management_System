#include <iostream>
#include "Airline.h"

using namespace std;

int main()
{
    Airline airline;
    int choice;

    do
    {
     cout << endl;
cout << "******** AIRLINE RESERVATION SYSTEM ********" << endl;
cout << endl;

cout << " [1] Add Flight" << endl;
cout << " [2] Display Flights" << endl;
cout << " [3] Register Passenger" << endl;
cout << " [4] Display Passengers" << endl;
cout << " [5] Book Ticket" << endl;
cout << " [6] Cancel Ticket" << endl;
cout << " [7] Exit" << endl;

cout << endl;
cout << "********************************************" << endl;
cout << "Enter Choice: ";
cin >> choice;

        switch(choice)
        {
        case 1:
            airline.addFlight();
            break;

        case 2:
            airline.displayFlights();
            break;

        case 3:
            airline.registerPassenger();
            break;

        case 4:
            airline.displayPassengers();
            break;

        case 5:
            airline.bookTicket();
            break;

        case 6:
            airline.cancelTicket();
            break;

        case 7:
            cout << "\n ******" << endl;
            cout << " Thanks for Using.";
            cout << "Program Over." << endl;
            break;

        default:
            cout << "\nInvalid Choice! Please enter 1-7." << endl;
        }

    } while(choice != 7);

    return 0;
}
