#ifndef LIMITED
#define LIMITED
#include "..\Strategy.h"

class Limited : public Strategy {
	virtual int interact(int stat, int incr) const override;
};

#endif