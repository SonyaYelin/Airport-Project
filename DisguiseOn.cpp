#include "DisguiseOn.h"
#include "DisguiseOff.h"
#include "FlightMarshal.h"

void DisguiseOn::disguiseOff(FlightMarshal& m)
{
	cout << "   going from DisguiseOn to DisguiseOff" << endl;
	m.setCurrent(*new DisguiseOff());
	delete this;
}


