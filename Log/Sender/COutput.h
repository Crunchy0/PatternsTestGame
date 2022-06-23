#ifndef COUTPUT
#define COUTPUT

#include <iostream>
#include "Output.h"

class COutput :public Output {
public:
	virtual ostream& getOut() override;
	virtual void send(Subscriber* sub) override;
};

#endif