#include "Airline.h"
using namespace std;

Airline* Airline::airline = nullptr;

Airline::Airline(const string& name, int maxNumOfFlights): name(name), maxNumOfFlights(maxNumOfFlights)
{
}

Airline& Airline::getInstance(const string& name, int maxNumOfFlights)
{
	if (airline == nullptr)
		airline = new Airline(name, maxNumOfFlights);
	return *airline;
}

Airline::~Airline() 
{
	delete airline;
}

// getters
const string& Airline::getName() const
{
	return name;
}

int Airline::getMaxNumOfFlights() const
{
	return maxNumOfFlights;
}

int Airline::getCurrentNumOfFlights() const
{
	return currentNumOfFlights;
}


// actions
void Airline::addEmployee(const Employee& employee, Flight& flight) throw (const string&)
{
	if (employees.size() == MAX_NUM_OF_EMPLOYEES)
		throw "max employees number has reached";

	employees.push_back((Employee*)&employee);
	flight.addEmployee(employee);
}

// chcek in to flight
void Airline::addPassenger(Passenger& passenger, const Flight& flight, PassengersClass::eClassType classType) throw (const string&)
{
	if (passengers.size() == MAX_NUM_OF_PASSENGERS)
		throw "max passengers number has reached";

	passengers.push_back((Passenger*)&passenger);
	flight.addPassenger(passenger, classType);
}

void Airline::allowFlight(const Flight& flight) const //call Flight::takeOff
{
	flight.takeOff();
}

void Airline::allowLanding(const Flight& flight) const //call Flight::land
{
	flight.land();
}

void Airline::orderMeal(Passenger& passenger, Passenger::eMeal meal) const throw (const string&)
{
	passenger.orderMeal(meal);
}

void Airline::serveFood(const Flight& flight) const throw (const string&)
{
	flight.serveFood();
}

void Airline::preventKidnap(const Flight& flight) const
{
	flight.preventKidnap();
}

void Airline::showFlights() const
{
	cout << flights << endl;
}

void Airline::showAvaliableSeats(const Flight& flight) const
{
	flight.showAvaliableSeats();
}

// operators
const Airline& Airline::operator+=(const Flight& flight) //add flight before taking off
{
	if (currentNumOfFlights < maxNumOfFlights)
		flights.addToTail((Flight&)flight);

	currentNumOfFlights++;
	return *this;
}

const Airline& Airline::operator-=(const Flight& flight) //substract flight when landing
{
	
	flights.remove((Flight&)flight);
	
	return *this;
}
