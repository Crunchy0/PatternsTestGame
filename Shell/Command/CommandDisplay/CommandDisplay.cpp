#include "CommandDisplay.h"

CommandDisplay::CommandDisplay(Facade* r) {
	reciever = r;
}

void CommandDisplay::execute() {
	reciever->display();
}