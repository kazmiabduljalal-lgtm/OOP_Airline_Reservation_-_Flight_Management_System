#include <iostream>
#include "CharterFlight.h"

using namespace std;

CharterFlight::CharterFlight(
    string FN,
    string OR,
    string DES,
    string DATE,
    int SEATS,
    string holder,
    double fare
)
: Flight(FN, OR, DES, DATE , SEATS)
{
    contractHolder = holder;
    charterFare = fare;
}

double CharterFlight::calculateFare()
{
    return charterFare;
}

void CharterFlight::display()
{
	cout << " \n *************** " << endl;
    cout << " Charter Flight " << endl;
    cout << " *************** " << endl;
    
    cout << "Flight No        : " << Flight_No << endl;
    cout << "Origin           : " << Origin << endl;
    cout << "Destination      : " << Destination << endl;
    cout << "Departure Date   : " << Departure_Date << endl;
    cout << "Contract Holder  : " << contractHolder << endl;
    cout << "Charter Fare     : Rs " << calculateFare() << endl;
    cout << "Available Seats  : " << Available_Seats << "/" << Total_Seats << endl;
}
