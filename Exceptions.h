#ifndef EXCEPTIONS_H
#define EXCEPTIONS_H

#include <iostream>
#include <string>
using namespace std;

class FlightFullException
{
public:
    void message()
    {
        cout << "Error: Flight is Full! No available seats." << endl;
    }
};

class InvalidCancellationException
{
public:
    void message()
    {
        cout << "Error: Invalid Cancellation! Ticket not found or already cancelled." << endl;
    }
};

class PassengerNotFoundException
{
public:
    void message()
    {
        cout << "Error: Passenger not found!" << endl;
    }
};

class FlightNotFoundException
{
public:
    void message()
    {
        cout << "Error: Flight not found!" << endl;
    }
};

#endif
