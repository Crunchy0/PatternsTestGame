#ifndef EMPTYSUB
#define EMPTYSUB

#include "Subscriber.h"

class EmptySub :public Subscriber {
	virtual void write(ostream& out) override;
};

#endif