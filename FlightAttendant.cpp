#include "FlightAttendant.h"

FlightAttendant::FlightAttendant(const string& name): Employee(name)
{
}

void FlightAttendant::serveFood(const Seat &seat) const throw (const string&)
{
	if (!seat.isTaken())
		throw "seat is empty!";

	Passenger& p = seat.getPassenger();

	if (p.getIsEntitledToMeal())
	{
		cout << getName() << " is serving food to seat: " << seat << endl;
		p.setIsEntitledToMeal(false);
	}
}

