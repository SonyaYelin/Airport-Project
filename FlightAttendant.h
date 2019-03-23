#ifndef __ATTENDANT_H
#define __ATTENDANT_H

#include "Employee.h"
#include "Seat.h"
#include "Passenger.h"

class FlightAttendant : public Employee
{
public:
	FlightAttendant(const string& name);

	void serveFood(const Seat &seat) const throw (const string&);
};


#endif // __ATTENDANT_H
