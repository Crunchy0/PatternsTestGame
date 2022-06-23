#ifndef OUTPUT
#define OUTPUT

#include <fstream>
#include "..\Subscriber\Subscribers.h"

using namespace std;

class Output {
public:
	virtual ostream& getOut() = 0;
	virtual void send(Subscriber* sub) = 0;
};
#endif