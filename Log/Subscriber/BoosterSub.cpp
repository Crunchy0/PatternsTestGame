#include "BoosterSub.h"

BoosterSub::BoosterSub(int v) {
	value = v;
}

void BoosterSub::write(ostream& out) {
	out << "Booster (" << value << " points).\n";
}