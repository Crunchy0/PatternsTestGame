#ifndef HEALERFACTORY
#define HEALERFACTORY

#include "..\Factory.h"
#include "..\Element\Healer\Healer.h"

class HealerFactory :public Factory {
public:
	virtual Element* createElement() const override;
};

#endif