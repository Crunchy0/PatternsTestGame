#include "CommandExit.h"

CommandExit::CommandExit(Facade* r) {
	reciever = r;
}

void CommandExit::execute() {
	reciever->exit();
}