#ifndef FACTORY
#define FACTORY

#include "Element/Element.h"

class Factory {
public:
	virtual Element* createElement() const = 0;
};

#endif