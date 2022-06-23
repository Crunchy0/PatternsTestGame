#include "Invoker.h"

Invoker::Invoker(Command* c) {
	command = c;
}

Invoker::~Invoker() {
	removeCommand();
}

void Invoker::setCommand(Command* c) {
	removeCommand();
	command = c;
}

void Invoker::removeCommand() {
	command = nullptr;
}

void Invoker::executeCommand() {
	command->execute();
}