#include "Passenger.h"

const string Passenger::meals[Passenger::NUM_OF_MEAL_TYPES] = { "VEGAN", "KOSHER", "GLUTEN_FREE" };

Passenger::Passenger(const string& name, int id): FlightObserver(), name(name), id(id), seat(nullptr)
{
}

// getters
const Seat& Passenger::getSeat() const
{
	return *seat;
}

const string& Passenger::getName() const 
{
	return name;
}

int Passenger::getId() const
{
	return id;
}

bool Passenger::getIsEntitledToMeal() const
{
	return isEntitledToMeal;
}
// setters
void Passenger::setSeat(const Seat& seat)
{
	this->seat = (Seat*)&seat;
}

void Passenger::setIsEntitledToMeal(bool isEntitledToMeal)
{
	this->isEntitledToMeal = isEntitledToMeal;
}

// actions
void Passenger::orderMeal(eMeal mealType) throw (const string&)
{
	if (this->isEntitledToMeal)
		this->mealType = mealType;
	else
		throw "not Entitled To Meal";
}

void Passenger::notifyFlightTimeChanged(const Time &flightTime, const Time &landTime) const
{
	cout << "flight times have changed!! new times: " << endl;
	cout << "flightTime: " << flightTime << endl;
	cout << "landTime: " << landTime << endl;
}

void Passenger::toOs(ostream& os) const
{
	os << "passenger id: " << id;
	os << ", passenger name: " << name << endl;
	if (seat != nullptr)
		os << "passenger seat: " << *(seat);
	if (isEntitledToMeal)
	{
		os << endl;
		os << "passenger meal type: " << meals[mealType];
	}
}
	