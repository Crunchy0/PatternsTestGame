#ifndef BOOSTERFACTORY
#define BOOSTERFACTORY

#include "..\Factory.h"
#include "..\Element\Booster\Booster.h"

class BoosterFactory :public Factory {
public:
	virtual Element* createElement() const override;
};

#endif