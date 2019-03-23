#include "Seat.h"
#include "Passenger.h"

const string Seat::locations[Seat::NUM_OF_LOCATIONS] = { "WINDOW", "MIDDLE", "AISLE" };

Seat::Seat(int row, int seatInRow, eLocation location): thePassanger(nullptr), row(row), seatInRow(seatInRow), location(location)
{
}

// getters
bool Seat::isTaken() const
{
	return thePassanger != nullptr;
}

int Seat::getRow() const
{
	return row;
}
int Seat::getSeatInRow() const
{
	return seatInRow;
}

// setters
void Seat::setTaken(Passenger& passanger)
{
	this->thePassanger = &passanger;
}

Passenger& Seat::getPassenger() const
{
	return *thePassanger;
}

ostream& operator<<(ostream& os, const Seat& seat)
{
	os << "seat row: " << seat.row
		<< " seat number: " << seat.seatInRow
		<< " seat location: " << seat.locations[seat.location] << endl;

	return os;
}