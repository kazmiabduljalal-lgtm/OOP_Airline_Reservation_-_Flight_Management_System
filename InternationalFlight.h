#ifndef INTERNATIONALFLIGHT_H
#define INTERNATIONALFLIGHT_H

#include "Flight.h"

class InternationalFlight : public Flight
{
private:
    bool visaRequired;
    double internationalTax;
    double baseFare;

public:

    InternationalFlight(
        string FN    = "",
        string OR   = "",
        string DES  = "",
        string DATE  = "",
        int seats    = 0,
        bool visa    = false,
        double tax   = 0.0,
        double fare  = 25000.0
    );

    double calculateFare();
    void display();

    // Getters for file handling
    bool   getVisaRequired()      { return visaRequired; }
    double getInternationalTax()  { return internationalTax; }
    double getBaseFare()          { return baseFare; }
    string getOrigin()            { return Origin; }
    string getDestination()       { return Destination; }
    string getDate()              { return Departure_Date; }
};

#endif
