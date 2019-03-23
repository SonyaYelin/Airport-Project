#ifndef __FLIGHT_MARSHAL_H
#define __FLIGHT_MARSHAL_H

#include "Employee.h"
#include "Passenger.h"
#include "State.h"

class state;
class FlightMarshal : public Employee, public Passenger
{
private:
	float seniority;
	bool carringWeapon;
	State *current;

public:
	FlightMarshal(const string& name, int id, float seniority, bool carringWeapon);
	~FlightMarshal();

	// getters
	virtual const string& getName() const override;
	float getSeniority() const;
	bool isCarringWeapon() const;

	// setters
	void setSeniority(float seniority);
	void setCurrent(const State &s);

	// actions
	void preventKidnap();
	virtual void toOs(ostream& os) const override;
};

#endif __FLIGHT_MARSHAL_H