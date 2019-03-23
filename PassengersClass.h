#ifndef __PASS_CLASS_H
#define __PASS_CLASS_H
#pragma warning(disable: 4290)
using namespace std;

#include <iostream>
#include "Passenger.h"
#include <vector>

class PassengersClass
{
public:
	enum eClassType {FIRST, BUSSINESS, ECONOMY};

private:
	static const int MAX_NUM_OF_SEATS = 30;
	static const int SEATS_IN_ROW = 3;
	static const int NUM_OF_CLASS_TYPES = 3;
	static const string types[NUM_OF_CLASS_TYPES];

	eClassType type;
	int currentNumOfSeats;
	vector<Seat*> seats;

public:
	PassengersClass(eClassType type = ECONOMY);
	PassengersClass(const PassengersClass& other);
	~PassengersClass();
	const PassengersClass& operator=(const PassengersClass& other);

	// getters & setters
	eClassType getType() const;
	const vector<Seat*> getSeats() const;
	int getMaxNumOfSeats() const;
	void setType(eClassType type);

	// actions
	void deleteAllSeats();
	const Seat& assignAvailableSeat(Passenger& p) throw (const string&); //no seat was found
	Seat* operator[](int index); //returns seat[index]
	void showAvaliableSeats() const;
};


#endif __PASS_CLASS_H