#include "Employee.h"

int Employee::idGenerator = 0;

Employee::Employee(const string& name): name(name), employeeID(idGenerator++)
{
}

// getters & setters
int Employee::getEmployeeID() const
{
	return employeeID;
}

const string& Employee::getName() const 
{
	return name;
}

void Employee::setName(const string& name)
{
	this->name = name;
}

ostream& operator<<(ostream& os, const Employee& employee)
{
	os << "Employee Type: " << (typeid(employee).name() + 6) << ", employee id: " << employee.employeeID << ", employee name: " << employee.name << endl;
	employee.toOs(os);

	return os;
}