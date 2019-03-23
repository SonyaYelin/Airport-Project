#ifndef __EMPLOYEE_H
#define __EMPLOYEE_H

#include <iostream>
#include <string>
using namespace std;

class Employee
{
	static int idGenerator;
	int employeeID;
	string name;

public:
	Employee(const string& name);
	Employee(const Employee& other) = delete;
	const Employee& operator=(const Employee& other) = delete;

	// getters & setters
	int getEmployeeID() const;
	virtual const string& getName() const;
	void setName(const string& name);

	virtual void toOs(ostream& os) const {};

	// operators
	friend ostream& operator<<(ostream& os, const Employee& employee);
};

#endif // __EMPLOYEE_H