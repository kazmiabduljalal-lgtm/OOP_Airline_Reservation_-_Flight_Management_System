#ifndef CHARTERFLIGHT_H
#define CHARTERFLIGHT_H

#include "Flight.h"

class CharterFlight : public Flight
{
private:
    string contractHolder;
    double charterFare;

public:

    CharterFlight(
        string FN     = "",
        string OR    = "",
        string DES   = "",
        string DATE   = "",
        int SEATS     = 0,
        string holder = "",
        double fare   = 99999.0
    );

    double calculateFare();
    void display();

    // Getters for file handling
    string getContractHolder()  { return contractHolder; }
    double getCharterFare()     { return charterFare; }
    string getOrigin()          { return Origin; }
    string getDestination()     { return Destination; }
    string getDate()            { return Departure_Date; }
};

#endif
