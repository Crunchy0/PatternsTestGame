#include "Limited.h"

int Limited::interact(int stat, int incr) const{
	if (stat + incr > 0 && stat + incr < 101) {
		return incr;
	}
	return 0;
}