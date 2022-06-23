#ifndef BOOSTERSUB
#define BOOSTERSUB

#include "Subscriber.h"

class BoosterSub :public Subscriber {
private:
	int value;
public:
	explicit BoosterSub(int v);
	virtual void write(ostream& out) override;
};

#endif