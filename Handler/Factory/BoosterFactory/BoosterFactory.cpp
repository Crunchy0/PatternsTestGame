#include "BoosterFactory.h"

Element* BoosterFactory::createElement() const {
	return new Booster();
}