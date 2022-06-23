#include "CommandMoveBackward.h"

CommandMoveBackward::CommandMoveBackward(Facade* r) {
	reciever = r;
}

void CommandMoveBackward::execute() {
	reciever->move(false);
}