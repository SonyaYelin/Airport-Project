#include "DisguiseOff.h"
#include "DisguiseOn.h"
#include "FlightMarshal.h"

void DisguiseOff::disguiseOn(FlightMarshal& m)
{
		cout << "   going from OFF to ON" << endl;
		m.setCurrent(*new DisguiseOn());
		delete this;
}