#include "CommandTurnRight.h"

CommandTurnRight::CommandTurnRight(Facade* r) {
	reciever = r;
}

void CommandTurnRight::execute() {
	reciever->turn(true);
}