#include "Flight.h"

const string Flight::types[Flight::NUM_OF_CLASSES] = { "JUMBO", "BOEING", "AIRBUS" };

Flight::Flight(const string& flightNumber, const string& destination, ePlaneType type,
				Time flightTime, Time landTime, int maxNumOfEmployees)
				: flightNumber(flightNumber), destination(destination), flightTime(flightTime),
					landTime(landTime), maxNumOfEmployees(maxNumOfEmployees), type(type)
{	
	passengersClasses.push_back(new PassengersClass(PassengersClass::BUSSINESS));
	passengersClasses.push_back(new PassengersClass(PassengersClass::FIRST));
	passengersClasses.push_back(new PassengersClass(PassengersClass::ECONOMY));
}

Flight::~Flight()
{
	vector<PassengersClass*>::const_iterator itr = passengersClasses.begin();
	vector<PassengersClass*>::const_iterator itrEnd = passengersClasses.end();

	for (itr; itr != itrEnd; ++itr)
		delete *itr;
	
	passengersClasses.clear();
}

// getters
const string& Flight::getFlightNumber() const
{
	return flightNumber;
}

const string& Flight::getDestination() const
{
	return destination;
}

Flight::ePlaneType Flight::getType() const
{
	return type;
}

const Time& Flight::getFlightTime() const
{
	return flightTime;
}

const Time& Flight::getLandTime() const
{
	return landTime;
}

const vector<PassengersClass*> Flight::getPassengersClasses() const
{
	return passengersClasses;
}

// actions
void Flight::addEmployee(const Employee& employee) throw (const string&) //throws exception when max employees has reached
{
	if (employees.size() > (size_t)maxNumOfEmployees) // casting to unsigned value to remove warning
		throw "max number of employees has reached";

	employees.push_back((Employee*)&employee);
}

void Flight::addPassenger(Passenger& passenger, PassengersClass::eClassType type) const throw (const string&) //call PassengersClass::findAvailableSeat, throws exceptions if there's no available seat
{
	Seat& seat = (Seat&)passengersClasses[type]->assignAvailableSeat(passenger);
	passenger.setSeat(seat);
	return;
}

void Flight::takeOff() const //find the captain and call Captain::orderToTakeOff and Pilot::takeOff
{
	vector<Employee*>::const_iterator itr = employees.begin();
	vector<Employee*>::const_iterator itrEnd = employees.end();
	bool captainNotFound = true;
	bool pilotNotFounf = true;

	for (itr; itr != itrEnd && (captainNotFound || pilotNotFounf); ++itr)
	{
		if (typeid(**itr) == typeid(Captain))
		{
			((Captain*)*itr)->orderToTakeOff();
			captainNotFound = false;
		}
		if (typeid(**itr) == typeid(Pilot))
		{
			((Pilot*)*itr)->takeOff();
			pilotNotFounf = false;
		}
	}
}

void Flight::land() const
{
	vector<Employee*>::const_iterator itr = employees.begin();
	vector<Employee*>::const_iterator itrEnd = employees.end();
	bool captainNotFound = true;
	bool pilotNotFounf = true;

	for (itr; itr != itrEnd && (captainNotFound || pilotNotFounf); ++itr)
	{
		if (typeid(**itr) == typeid(Captain))
		{
			((Captain*)*itr)->orderToLand();
			captainNotFound = false;
		}

		if (typeid(**itr) == typeid(Pilot))
		{
			((Pilot*)*itr)->land();
			pilotNotFounf = false;
		}
	}
}

const FlightAttendant& Flight::getFlightAttendant() const  throw (const char*)
{
	vector<Employee*>::const_iterator itr = employees.begin();
	vector<Employee*>::const_iterator itrEnd = employees.end();

	for (itr; itr != itrEnd ; ++itr)
	{
		if (typeid(**itr) == typeid(FlightAttendant))
			return ((FlightAttendant&)(**itr));
	}
	throw "no Flight Attendant";
}

void Flight::serveFood() const  throw (const string&)
{
	const FlightAttendant& flightAttendant = getFlightAttendant();
	 
	for (int i = 0; i < NUM_OF_CLASSES; i++)
	{
		vector<Seat*> seats = passengersClasses[i]->getSeats();

		vector<Seat*>::const_iterator itr = seats.begin();
		vector<Seat*>::const_iterator itrEnd = seats.end();
		for (itr; itr != itrEnd; ++itr)
		{
			if ((*itr)->isTaken())
				flightAttendant.serveFood(**itr);

		}
	}
}

void Flight::preventKidnap() const
{
	vector<Employee*>::const_iterator itr = employees.begin();
	vector<Employee*>::const_iterator itrEnd = employees.end();

	for (itr; itr != itrEnd; ++itr)
	{
		if (typeid(**itr) == typeid(FlightMarshal))
			((FlightMarshal*)*itr)->preventKidnap();
	}
}

void Flight::showAvaliableSeats() const
{
	for (int i = 0; i < NUM_OF_CLASSES; i++)
		passengersClasses[i]->showAvaliableSeats();
}

void Flight::notifyAllRegistered() const
{
	vector<FlightObserver*>::const_iterator itr = viewers.begin();
	vector<FlightObserver*>::const_iterator itrEnd = viewers.end();

	for (; itr != itrEnd; ++itr)
		(*itr)->notifyFlightTimeChanged(flightTime, landTime);

}

// operators
bool Flight::operator==(const Flight& other) const
{
	if (flightNumber == other.flightNumber)
		return true;
	return false;
}

ostream& operator<<(ostream& os, const Flight& flight)
{
	os << "------ flight ------ " << endl;
	os << "flight number: " << flight.flightNumber << endl;
	os << "destination: " << flight.destination << endl;
	os << "flight time: " << flight.flightTime << endl;
	os << "land time: " << flight.landTime << endl;
	os << "plane type: " << flight.types[flight.type] << endl;
	os << "plane employees: " << endl;

	vector<Employee*>::const_iterator itr = flight.employees.begin();
	vector<Employee*>::const_iterator itrEnd = flight.employees.end();

	for (itr; itr != itrEnd; ++itr)
	{
		os << "--- employee: ---" << endl;
		os << (**itr) << endl;
	}
	return os;
}