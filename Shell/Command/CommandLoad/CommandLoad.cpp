#include "CommandLoad.h"

CommandLoad::CommandLoad(Facade* r) {
	reciever = r;
}

void CommandLoad::execute() {
	reciever->load();
}