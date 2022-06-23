#include "Booster.h"
#include <cstdlib>

Booster::Booster() {
	type = 2;
	accelerator = rand()%6 + 10;
}

int Booster::getBonus() const {
	return accelerator;
}

int Booster::getType() const {
	return type;
}