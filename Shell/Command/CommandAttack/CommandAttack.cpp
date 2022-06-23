#include "CommandAttack.h"

CommandAttack::CommandAttack(Facade* r) {
	reciever = r;
}

void CommandAttack::execute() {
	reciever->attackEnemies();
}