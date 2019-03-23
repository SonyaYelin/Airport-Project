#ifndef __TIME_H
#define __TIME_H
#pragma warning( disable : 4290 )
#include <iostream>

using namespace std;

class Time
{
private:
	int hours, minutes;

public:
	Time(int hours, int minutes);
	// getters
	int getMinutes() const;
	int getHours() const;

	// setters
	void setMinutes(int m) throw (const string&);
	void setHours(int h) throw (const string&);

	friend ostream& operator<<(ostream& os, const Time& time);
};

#endif // __TIME_H

