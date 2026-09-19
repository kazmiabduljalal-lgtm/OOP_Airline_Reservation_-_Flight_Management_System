#include <iostream>
#include "BusinessPassenger.h"

using namespace std;

BusinessPassenger::BusinessPassenger(int id, string n)
: Passenger(id, n)
{
}

double BusinessPassenger::getRefundPercentage()
{
    return 75.0;
}

void BusinessPassenger::display()
{
	cout << " \n *************** " << endl;
    cout << " Business Passenger " << endl;
    cout << " *************** "<< endl;
    
    cout << "Name             : " << name << endl;
    cout << "Passenger ID     : " << passengerId << endl;
    cout << "Refund Percentage: " << getRefundPercentage() << "%" << endl;
}
