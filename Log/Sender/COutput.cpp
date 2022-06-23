#include "COutput.h"

ostream& COutput::getOut() {
	return std::cout;
}

void COutput::send(Subscriber* sub) {
	sub->write(std::cout);
}