#ifndef __STATE_H
#define __STATE_H
#include <iostream>

using namespace std;
class FlightMarshal;
class State
{
public:
	virtual void disguiseOn(FlightMarshal& m) 
	{
		cout << "   already disguise On\n";
	}

	virtual void disguiseOff(FlightMarshal& m) 
	{
		cout << "   already disguise Off\n";
	}
}; 

#endif // __STATE_H