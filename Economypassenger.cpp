#include <iostream>
#include "EconomyPassenger.h"

using namespace std;

EconomyPassenger::EconomyPassenger(int id, string n)
: Passenger(id, n)
{
}

double EconomyPassenger::getRefundPercentage()
{
    return 50.0;
}

void EconomyPassenger::display()
{
	cout << "\n *************** " << endl; // designing output
    cout << "Economy Passenger" << endl;
    cout << " *************** " << endl;
    
    cout << "Passenger ID     : " << passenger_Id << endl;
    cout << "Name             : " << name << endl;
    cout << "Refund Percentage: " << getRefundPercentage() << "%" << endl;
}
