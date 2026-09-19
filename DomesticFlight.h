#ifndef DOMESTICFLIGHT_H
#define DOMESTICFLIGHT_H

#include "Flight.h"

class DomesticFlight : public Flight
{
private:
    double baseFare;

public:

    DomesticFlight(
        string FN   = "",
        string OR  = "",
        string DES = "",
        string DATE = "",
        int SEATS   = 0,
        double fare = 10.0
    );

    double calculateFare();
    void display();

    // Getters for file handling
    double getBaseFare()      { return baseFare; }
    string getOrigin()        { return Origin; }
    string getDestination()   { return Destination; }
    string getDate()          { return Departure_Date; }
};

#endif
