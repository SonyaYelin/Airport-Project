#ifndef __PASSENGER_H
#define __PASSENGER_H

#include <iostream>
#include <string>
#include "Seat.h"
#include "FlightObserver.h"

using namespace std;

class Passenger: public FlightObserver
{
public:
	enum eMeal {VEGAN, KOSHER, GLUTEN_FREE};

private:
	static const int NUM_OF_MEAL_TYPES = 3;
	static const string meals[NUM_OF_MEAL_TYPES];

	int id;
	string name;
	Seat* seat; // nullptr when not allocated to passenger
	eMeal mealType;
	bool isEntitledToMeal;

public:
	Passenger(const string& name, int id);
	Passenger(const Passenger& other) = delete;
	const Passenger& operator=(const Passenger& other) = delete;

	// getters
	const Seat& getSeat() const;
	virtual const string& getName() const;
	int getId() const;
	bool getIsEntitledToMeal() const;

	// setters
	void setSeat(const Seat& seat);
	void setIsEntitledToMeal(bool isEntitledToMeal);

	 // functions
	void orderMeal(eMeal mealType) throw (const string&);
	virtual void notifyFlightTimeChanged(const Time &flightTime, const Time &landTime) const;

	virtual void toOs(ostream& os) const;

};

#endif __PASSENGER_H
