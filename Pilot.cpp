#include "Pilot.h"

Pilot::Pilot(const string& name, float seniority): Employee(name), seniority(seniority)
{

}

void Pilot::takeOff() const
{
	cout << "We are now taking-off!!!" << endl;
}

void Pilot::land() const
{
	cout << "We are now landing!!!" << endl;
}

void Pilot::toOs(ostream& os) const
{
	os << "pilot seniority: " << seniority << endl;
}


