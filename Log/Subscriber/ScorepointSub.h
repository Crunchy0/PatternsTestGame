#ifndef SCOREPOINTSUB
#define SCOREPOINTSUB

#include "Subscriber.h"

class ScorepointSub :public Subscriber {
private:
	int value;
public:
	explicit ScorepointSub(int v);
	virtual void write(ostream& out) override;
};

#endif