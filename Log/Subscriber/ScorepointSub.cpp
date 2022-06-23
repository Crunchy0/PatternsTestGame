#include "ScorepointSub.h"

ScorepointSub::ScorepointSub(int v) {
	value = v;
}

void ScorepointSub::write(ostream& out) {
	out << "Scorepoint (" << value << " points).\n";
}