#ifndef __FLIGHT_H
#define __FLIGHT_H

#include <time.h>
#include "PassengersClass.h"
#include "Time.h"
#include "FlightObserver.h"
#include <iostream>
#include <string>
#include <vector>
#include "Captain.h"
#include "FlightAttendant.h"
#include "FlightMarshal.h"

class Flight
{
public:
	enum ePlaneType {JUMBO, BOEING, AIRBUS};

private:
	static const int NUM_OF_CLASSES = 3;
	static const string types[NUM_OF_CLASSES];

	int maxNumOfEmployees;

	Time flightTime;
	Time landTime;
	
	ePlaneType type;

	string flightNumber;
	string destination;

	vector<Employee*> employees;
	vector<PassengersClass*> passengersClasses;
	vector<FlightObserver*> viewers;

	const FlightAttendant& getFlightAttendant() const throw (const string&);
	void notifyAllRegistered() const;

public:
	Flight(const string& flightNumber, const string& destination, ePlaneType type,
			Time flightTime, Time landTime, int maxNumOfEmployees);
	~Flight();
	Flight(const Flight& other) = delete;
	const Flight& operator=(const Flight& other) = delete;

	// getters
	const string& getFlightNumber() const;
	const string& getDestination() const;
	ePlaneType getType() const;
	const Time &getFlightTime() const;
	const Time &getLandTime() const;
	const vector<PassengersClass*> getPassengersClasses() const;
	
	// actions
	void addEmployee(const Employee& employee) throw (const string&); 
	void addPassenger(Passenger& passenger, PassengersClass::eClassType type) const throw (const string&); 
	void takeOff() const;
	void land() const;
	void serveFood() const throw (const string&);
	void preventKidnap() const;
	void showAvaliableSeats() const;

	// operators
	friend ostream& operator<<(ostream& os, const Flight& flight);
	bool operator==(const Flight& other) const;
};

#endif __FLIGHT_H