#include <iostream>
#include "FirstClassPassenger.h"

using namespace std;

FirstClassPassenger::FirstClassPassenger(int id, string n)
: Passenger(id, n)
{
}

double FirstClassPassenger::getRefundPercentage()
{
    return 90.0;
}

void FirstClassPassenger::display()
{
	cout << " \n *************** " << endl;
    cout << " First Class Passenger " << endl;
    cout << " *************** " << endl;
    
    cout << "Passenger ID     : " << passengerId << endl;
    cout << "Name             : " << name << endl;
    cout << "Refund Percentage: " << getRefundPercentage() << "%" << endl;
}
