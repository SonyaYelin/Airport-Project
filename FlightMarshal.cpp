#include "FlightMarshal.h"
#include "DisguiseOn.h"

FlightMarshal::FlightMarshal(const string& name, int id, float seniority, bool carringWeapon)
							: Employee(name), Passenger(name, id), current(new DisguiseOn()),
								seniority(seniority), carringWeapon(carringWeapon)
{
}

FlightMarshal::~FlightMarshal()
{
	delete(current);
}

// getters
const string& FlightMarshal::getName() const 
{
	return ((Employee*)this)->getName();
}

float FlightMarshal::getSeniority() const
{
	return seniority;
}

bool FlightMarshal::isCarringWeapon() const
{
	return carringWeapon;
}

// setters
void FlightMarshal::setSeniority(float seniority)
{
	this->seniority = seniority;
}

void FlightMarshal::setCurrent(const State &s)
{ 
	current = (State*) &s;
}

void FlightMarshal::preventKidnap() 
{
	cout << "There will be no kidnap on my watch" << endl;
	current->disguiseOff((FlightMarshal&)*this);
}

void FlightMarshal::toOs(ostream& os) const
{
	Passenger::toOs(os);
	os << "flight Marshal seniority: " << seniority << endl;
	os << "flight Marshal carring Weapon: " << carringWeapon << endl;
}
