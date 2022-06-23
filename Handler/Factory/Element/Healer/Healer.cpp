#include "Healer.h"

Healer::Healer() {
	type = 1;
	hp = 10;
}

int Healer::getBonus() const {
	return hp;
}

int Healer::getType() const {
	return type;
}