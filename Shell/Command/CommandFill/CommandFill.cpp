#include "CommandFill.h"

CommandFill::CommandFill(Facade* r) {
	reciever = r;
}

void CommandFill::execute() {
	reciever->fill();
}