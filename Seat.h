#ifndef __SEAT_H
#define __SEAT_H
#include <iostream>

using namespace std;

class Passenger;
class Seat
{
public:
	enum eLocation {WINDOW, MIDDLE, AISLE };
private:
	static const int NUM_OF_LOCATIONS = 3;
	static const string locations[NUM_OF_LOCATIONS];

	int row;
	int seatInRow;
	Passenger *thePassanger; // if nullptr-> seat is not taken 
	eLocation location;

public:
	Seat(int row, int seatInRow, eLocation location = WINDOW);
	
	// getters
	bool isTaken() const;
	int getRow() const;
	int getSeatInRow() const;

	// setters
	Passenger& getPassenger() const;
	void setTaken(Passenger& passanger);

	friend ostream& operator<<(ostream& os, const Seat& seat);
};

#endif __SEAT_H
