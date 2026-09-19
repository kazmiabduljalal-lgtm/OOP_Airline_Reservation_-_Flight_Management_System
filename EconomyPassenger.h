#ifndef ECONOMYPASSENGER_H
#define ECONOMYPASSENGER_H

#include "Passenger.h"

class EconomyPassenger : public Passenger
{
public:

    EconomyPassenger(int id = 0, string n = "");

    double getRefundPercentage();

    void display();
};

#endif
