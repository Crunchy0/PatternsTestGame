#include "HealerSub.h"

HealerSub::HealerSub(int v) {
	value = v;
}

void HealerSub::write(ostream& out) {
	out << "Healer (" << value << " points).\n";
}