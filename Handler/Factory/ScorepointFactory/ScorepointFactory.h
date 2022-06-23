#ifndef SCOREPOINTFACTORY
#define SCOREPOINTFACTORY

#include "..\Factory.h"
#include "..\Element\Scorepoint\Scorepoint.h"

class ScorepointFactory :public Factory {
public:
	virtual Element* createElement() const override;
};

#endif