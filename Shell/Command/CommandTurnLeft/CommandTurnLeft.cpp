#include "CommandTurnLeft.h"

CommandTurnLeft::CommandTurnLeft(Facade* r) {
	reciever = r;
}

void CommandTurnLeft::execute() {
	reciever->turn(false);
}