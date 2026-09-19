#ifndef TICKET_H
#define TICKET_H

#include <iostream>
#include "Flight.h"
#include "Passenger.h"

using namespace std;
// crating class ticket
class Ticket
{
private:

    int ticket_Id;
    Flight* flight;
    Passenger* passenger;
    int seat_Number;
    double fare_Paid;
    bool active;

public:

    Ticket(
        int id       = 0,
        Flight* f    = NULL,
        Passenger* p = NULL,
        int seat     = 0,
        double fare  = 0.0
    );

    void display() const;

    int    getTicket_Id()   const;
    bool   isActive()      const;
    void   cancel();

    Flight*    getFlight()     const;
    Passenger* getPassenger()  const;
    double     getFare_Paid()   const;
    int        getSeat_Number() const;
	
	// operator overloading 
	bool operator==(const Ticket& other)const;
	
	// output operator
	friend ostream& operator<<(ostream& out,const Ticket& t );
};

#endif
  
