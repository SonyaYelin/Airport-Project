#ifndef __CAPTAIN_H
#define __CAPTAIN_H

#include "Pilot.h"

class Captain : public Pilot
{
private:
	int numOfPassengersAllowed;
public:
	Captain::Captain(const string& name, float seniority, int numOfPassengersAllowed);
	
	// getters
	int getNumOfPassengersAllowed() const;

	// functions
	void speekInMichrophone() const;
	void orderToTakeOff() const; //tell the pilots to take off
	void orderToLand() const; //tell the pilots to land
	void toOs(ostream& os) const override;
};

#endif __CAPTAIN_H