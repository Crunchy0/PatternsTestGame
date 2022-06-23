#include "Strategy.h"
#include "Strategies.h"

Strategy* Strategy::chooseStrategy(int type) {
	if (type == 1) {
		return new Limited();
	}
	else{
		return new Unlimited();
	}
}