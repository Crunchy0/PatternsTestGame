#include "HealerFactory.h"

Element* HealerFactory::createElement() const {
	return new Healer();
}