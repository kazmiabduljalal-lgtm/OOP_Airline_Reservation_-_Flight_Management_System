
#include <iostream>
#include "DomesticFlight.h"

using namespace std;

DomesticFlight::DomesticFlight(
    string FN,
    string OR,
    string DES,
    string DATE,
    int SEATS,
    double fare
)
    : Flight(FN, OR, DES, DATE, SEATS)
{
    baseFare = fare;
}

double DomesticFlight::calculateFare()
{
    return baseFare;
}

void DomesticFlight::display()
{
    cout << "\n *************** " << endl;
    cout << " Domestic Flight " << endl;
    cout << " *************** " << endl;

    cout << "Flight No        : " << Flight_No << endl;
    cout << "Origin           : " << Origin << endl;
    cout << "Destination      : " << Destination << endl;
    cout << "Departure Date   : " << Departure_Date << endl;
    cout << "Base Fare        : Rs " << calculateFare() << endl;
    cout << "Available Seats  : " << Available_Seats << "/" << Total_Seats << endl;
}
