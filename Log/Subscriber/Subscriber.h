#ifndef SUBSCRIBER
#define SUBSCRIBER

#include <string>
#include <fstream>

using namespace std;

class Subscriber {
public:
	virtual void write(ostream& out) = 0;
};

#endif