#include "Time.h"


Time::Time(int hours, int minutes) 
{
	setMinutes(minutes);
	setHours(hours);
}

// getters & setters
int Time::getMinutes() const
{
	return minutes;
}
int Time::getHours() const
{
	return hours;
}

void Time::setMinutes(int m) throw (const string&)
{
	if (m >= 0)
		minutes = m;
	else
		throw "minutes < 0";
}
void Time::setHours(int h) throw (const string&)
{
	if (h >= 0)
		hours = h;
	else
		throw "hours < 0";
}

ostream& operator<<(ostream& os, const Time& time)
{
	os << "hours: " << time.hours << ", minutes: " << time.minutes;
	return os;
}

