#ifndef BOOSTER
#define BOOSTER

#include "..\Element.h"

class Booster : public Element {
private:
	int type;
	int accelerator;
public:
	Booster();
	virtual int getBonus() const override;
	virtual int getType() const override;
};

#endif