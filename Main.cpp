#include <iostream>
using namespace std;

#include "Airline.h"
#include "FlightAttendant.h"
#include "Captain.h"
#include "FlightMarshal.h"

// part 3

void main()
{
	try
	{
		Airline& airline = Airline::getInstance("DT Airlines", 50);
		cout << "Welcome to " << airline.getName() << "!" << endl;

		Flight flight1("DT806", "New-York", Flight::BOEING, Time(1, 40), Time(13, 40), 20);
		airline += flight1;
		airline -= flight1;
		airline += flight1;

		Passenger p1("Hadar", 82756);
		p1.setIsEntitledToMeal(true);
		Passenger p2("Maor", 34672);
		p2.setIsEntitledToMeal(true);
		Passenger p3("Sergei", 28685);

		airline.addPassenger(p1, flight1, PassengersClass::ECONOMY);
		airline.addPassenger(p2, flight1, PassengersClass::ECONOMY);
		airline.addPassenger(p3, flight1, PassengersClass::BUSSINESS);

		FlightAttendant firstClassAttendant("Maayan");
		FlightAttendant bussinessClassAttendant("May");
		FlightAttendant economyClassAttendant("Yogev");

		Captain captain("Almog", 4, 100);
		Pilot pilot("Danielle", 3);
		FlightMarshal marshal("Ran", 8765, 8.5, true);

		airline.addEmployee(firstClassAttendant, flight1);
		airline.addEmployee(bussinessClassAttendant, flight1);
		airline.addEmployee(economyClassAttendant, flight1);
		airline.addEmployee(captain, flight1);
		airline.addEmployee(pilot, flight1);
		airline.addEmployee(marshal, flight1);
		airline.addPassenger(marshal, flight1);

		airline.allowFlight(flight1);

		airline.orderMeal(p1, Passenger::KOSHER);
		airline.serveFood(flight1);

		airline.serveFood(flight1);
		airline.preventKidnap(flight1);
		airline.allowLanding(flight1);
		airline.showFlights();
		airline -= flight1;
	}
	catch (const string& msg)
	{
		cout << msg << endl;
	}
	system("pause");
}
