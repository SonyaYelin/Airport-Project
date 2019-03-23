#ifndef __FLIGHT_OBSERVER_H
#define __FLIGHT_OBSERVER_H

#include "Time.h"
using namespace std;

class FlightObserver
{
public:
	virtual void notifyFlightTimeChanged(const Time &flightTime,const Time &landTime) const = 0;

};

#endif __FLIGHT_OBSERVER_H
