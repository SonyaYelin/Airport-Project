#ifndef __AIRLINE_H
#define __AIRLINE_H

#include "Flight.h"
#include "LinkedList.h"

class Airline
{
private:
	static const int MAX_NUM_OF_EMPLOYEES = 40;
	static const int MAX_NUM_OF_PASSENGERS = 100;

	int maxNumOfFlights;
	int currentNumOfFlights;
	string name;

	LinkedList<Flight> flights;
	vector<Passenger*> passengers;
	vector<Employee*> employees;

	static Airline* airline;
	Airline(const string& name, int maxNumOfFlights);

public:
	static Airline& getInstance(const string& name, int maxNumOfFlights);
	~Airline();
	Airline(const Airline& other) = delete;
	const Airline& operator=(const Airline& other) = delete;

	// getters 
	const string& getName() const;
	int getMaxNumOfFlights() const;
	int getCurrentNumOfFlights() const;

	// actions
	void addEmployee(const Employee& employee, Flight& flight) throw (const string&);
	void addPassenger(Passenger& passenger, const Flight& flight, PassengersClass::eClassType classType = PassengersClass::ECONOMY) throw (const string&);
	void allowFlight(const Flight& flight) const; //call Flight::takeOff
	void allowLanding(const Flight& flight) const; //call Flight::land
	void orderMeal(Passenger& passenger, Passenger::eMeal meal) const throw (const string&);
	void serveFood(const Flight& flight) const throw (const string&);
	void preventKidnap(const Flight& flight) const;
	void showFlights() const;
	void showAvaliableSeats(const Flight& flight) const;

	// operators
	const Airline& operator+=(const Flight& flight); 
	const Airline& operator-=(const Flight& flight); 
};

#endif __AIRLINE_H
