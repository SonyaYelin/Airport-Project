#ifndef __PILOT_H
#define __PILOT_H
using namespace std;

#include "Employee.h"

class Pilot : public Employee
{
private:
	float seniority;

public:
	Pilot(const string& name, float seniority);

	void takeOff() const;
	void land() const;
	void toOs(ostream& os) const override;

};

#endif __PILOT_H