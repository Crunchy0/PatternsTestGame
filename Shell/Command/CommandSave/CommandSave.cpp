#include "CommandSave.h"

CommandSave::CommandSave(Facade* r) {
	reciever = r;
}

void CommandSave::execute() {
	reciever->save();
}