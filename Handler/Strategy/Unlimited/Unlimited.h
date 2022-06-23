#ifndef UNLIMITED
#define UNLIMITED
#include "..\Strategy.h"

class Unlimited :public Strategy {
	virtual int interact(int stat, int incr) const override;
};

#endif