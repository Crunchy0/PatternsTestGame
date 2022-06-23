#include "Scorepoint.h"

Scorepoint::Scorepoint() {
	type = 0;
	points = 1;
}

int Scorepoint::getBonus() const {
	return points;
}

int Scorepoint::getType() const {
	return type;
}