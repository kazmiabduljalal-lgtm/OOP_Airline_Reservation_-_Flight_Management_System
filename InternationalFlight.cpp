#include <iostream>
#include "InternationalFlight.h"

using namespace std;

InternationalFlight::InternationalFlight(
    string FN,
    string OR,
    string DES,
    string DATE,
    int SEATS,
    bool visa,
    double tax,
    double fare
)
: Flight(FN, OR, DES, DATE, SEATS)
{
    visaRequired = visa;
    internationalTax = tax;
    baseFare = fare;
}

double InternationalFlight::calculateFare()
{
    return baseFare + internationalTax;
}

void InternationalFlight::display()
{
	cout << "\n *************** " << endl;
    cout << " International Flight " << endl;
    cout << " \n *************** " << endl;
    
    cout << "Flight No        : " << Flight_No << endl;
    cout << "Origin           : " << Origin << endl;
    cout << "Destination      : " << Destination << endl;
    cout << "Departure Date   : " << Departure_Date << endl;
    cout << "Visa Required    : " << (visaRequired ? "Yes" : "No") << endl;
    cout << "International Tax: Rs " << internationalTax << endl;
    cout << "Total Fare       : Rs " << calculateFare() << endl;
    cout << "Available Seats  : " << Available_Seats << "/" << Total_Seats << endl;
}
