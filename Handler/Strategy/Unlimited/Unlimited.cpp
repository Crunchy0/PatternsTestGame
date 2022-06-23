#include "Unlimited.h"

int Unlimited::interact(int stat, int incr) const {
	if (stat + incr > 0) {
		return incr;
	}
	return 0;
}