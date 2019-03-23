#include "PassengersClass.h"

const string PassengersClass::types[PassengersClass::NUM_OF_CLASS_TYPES] = { "FIRST", "BUSSINESS", "ECONOMY" };

PassengersClass::PassengersClass(eClassType type): type(type), currentNumOfSeats(MAX_NUM_OF_SEATS)
{
	int i = 0, j = 0;
	while (i < MAX_NUM_OF_SEATS - SEATS_IN_ROW)
	{
		i += SEATS_IN_ROW;
		j++;
		seats.push_back(new Seat(j, 0, Seat::WINDOW));
		seats.push_back(new Seat(j, 1, Seat::MIDDLE));
		seats.push_back(new Seat(j, 2, Seat::AISLE));
	}
}

PassengersClass::PassengersClass(const PassengersClass& other): PassengersClass(other.type)
{
}

PassengersClass::~PassengersClass()
{
	deleteAllSeats();
}

const PassengersClass& PassengersClass::operator=(const PassengersClass& other)
{
	type = other.type;
	if (!seats.empty())
		deleteAllSeats();

	currentNumOfSeats = other.currentNumOfSeats;
	
	vector<Seat*>::const_iterator itr = other.seats.begin();

	for (int i = 0; (size_t)i < other.seats.size(); i++) // casting to unsigned num to remove warning
		seats.push_back(new Seat(**itr));
	
	return *this;
}

PassengersClass::eClassType PassengersClass::getType() const
{
	return this->type;
}

const vector<Seat*> PassengersClass::getSeats() const
{
	return seats;
}

void PassengersClass::setType(PassengersClass::eClassType type)
{
	this->type = type;
}

int PassengersClass::getMaxNumOfSeats() const
{
	return MAX_NUM_OF_SEATS;
}

void PassengersClass::deleteAllSeats()
{
	vector<Seat*>::const_iterator itr = seats.begin();
	vector<Seat*>::const_iterator itrEnd = seats.end();

	for (; itr != itrEnd; ++itr)
		delete(*itr);

	seats.clear();
}

const Seat& PassengersClass::assignAvailableSeat(Passenger& p) throw (const string&) //no seat was found
{
	if (currentNumOfSeats == 0)
		throw "no seat was found";

	int idx = MAX_NUM_OF_SEATS - currentNumOfSeats;
	seats[idx]->setTaken(p);
	currentNumOfSeats--;
	return *seats[idx];
}

Seat* PassengersClass::operator[](int index) //returns seat[index]
{
	if (index <= MAX_NUM_OF_SEATS)
		return seats[index];
	return nullptr;
}

void PassengersClass::showAvaliableSeats() const
{
	vector<Seat*>::const_iterator itr = seats.begin();
	vector<Seat*>::const_iterator itrEnd = seats.end();

	for (itr; itr != itrEnd; ++itr)
	{
		if (!(*itr)->isTaken())
			cout << (**itr) << endl;
	}
}