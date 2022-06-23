#ifndef HEALERSUB
#define HEALERSUB

#include "Subscriber.h"

class HealerSub : public Subscriber {
private:
	int value;
public:
	explicit HealerSub(int v);
	virtual void write(ostream& out) override;
};

#endif