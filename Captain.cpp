#include "Captain.h"

Captain::Captain(const string& name, float seniority, int numOfPassengersAllowed): Pilot(name, seniority), numOfPassengersAllowed(numOfPassengersAllowed)
{
}

// getters
int Captain::getNumOfPassengersAllowed() const
{
	return numOfPassengersAllowed;
}

// actions
void Captain::speekInMichrophone() const
{
	cout << "The captain speeks in michrophone" << endl;
}

void Captain::orderToTakeOff() const
{
	cout << "Dear passengers, Prepare to takeoff!" << endl;
}

void Captain::orderToLand() const //tell the pilots to land
{
	cout << "Dear passengers, In a few minutes we'il start landing, please remain setted and fasten your seatbelts!" << endl;
}

void Captain::toOs(ostream& os) const
{
	Pilot::toOs(os);
	os << "Captain num Of Passengers Allowed: " << numOfPassengersAllowed;
}