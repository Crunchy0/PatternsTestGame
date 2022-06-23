#include "CommandMoveForward.h"

CommandMoveForward::CommandMoveForward(Facade* r) {
	reciever = r;
}

void CommandMoveForward::execute() {
	reciever->move(true);
}