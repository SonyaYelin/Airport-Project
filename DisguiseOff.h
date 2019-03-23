#ifndef __OFF_H
#define __OFF_H
#include "State.h"

class DisguiseOff : public State
{
public:

	virtual void disguiseOn(FlightMarshal& m);
};

#endif // __OFF_H
