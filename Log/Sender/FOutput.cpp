#include "FOutput.h"

FOutput::FOutput() {
	file = new File("./LOGS.txt", 1);
}

FOutput::~FOutput() {
	delete file;
}

ostream& FOutput::getOut() {
	return file->getToWrite();
}

void FOutput::send(Subscriber* sub) {
	sub->write(getOut());
}