#ifndef FLIGHT_H
#define FLIGHT_H

#include <iostream>
#include <string>
using namespace std;

	//creating Abstract Class (Flight)

class Flight
{
	// data members of the class flight
protected:
    string Flight_No;
    string Origin;  //flight starting location
    string Destination;  // flight landing location
    string Departure_Date;
    int Total_Seats;
    int Available_Seats;

public:
  // flight class constructor
  
    Flight(
        string FN = "",
        string OR = "",
        string DES = "",
        string DATE = "",
        int SEATS = 0
    )
    {
        Flight_No = FN;
        Origin = OR;
        Destination = DES;
        Departure_Date = DATE;
        Total_Seats = SEATS;
        Available_Seats = SEATS;
    }
	// Pure Virtual functions
	
    virtual double calculateFare() = 0;

    virtual void display() = 0;
    // getter functions

    string getFlight_No()
    {
        return Flight_No;
    }

    int getAvailable_Seats()
    {
        return Available_Seats;
    }

    int getTotal_Seats()
    {
        return Total_Seats;
    }
	
	// booking a seats
	
    void bookSeat()
    {
        if(Available_Seats > 0)
        {
            Available_Seats--;
            cout << " Seat Booked Successfully. " << endl;
        }
    }
	
	// cancelling a seats
	
    void cancelSeat()
    {
        if(Available_Seats < Total_Seats)
        {
            Available_Seats++;
            cout << " Seat Canceled. " << endl;
        }
    }  
    // virtual  destructor 

    virtual ~Flight() {}
};

#endif
