#ifndef STRATEGY
#define STRATEGY

class Strategy {
public:
	virtual int interact(int stat, int incr) const = 0;
	static Strategy* chooseStrategy(int t);
};

#endif