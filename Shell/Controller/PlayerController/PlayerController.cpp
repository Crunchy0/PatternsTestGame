#include "Windows.h"
#include "PlayerController.h"

enum Commands {
	FILL,
	MOVEFWD,
	MOVEBWD,
	TURNLT,
	TURNRT,
	ATTACK,
	DISPLAY,
	SAVE,
	LOAD,
	EXIT,
};

PlayerController::PlayerController(Handler* h) {
	inv = new Invoker(nullptr);
	facade = new Facade(h);
	commands = new Command * [10]{ new CommandFill(facade),
								new CommandMoveForward(facade),
								new CommandMoveBackward(facade),
								new CommandTurnLeft(facade),
								new CommandTurnRight(facade),
								new CommandAttack(facade),
								new CommandDisplay(facade),
								new CommandSave(facade),
								new CommandLoad(facade),
								new CommandExit(facade)};
	/*inv->setCommand(commands[FILL]);
	inv->executeCommand();*/
}

PlayerController::~PlayerController() {
	removeFacade();
	delete inv;
	delete[] commands;
}

void PlayerController::removeFacade() {
	if (facade != nullptr) {
		delete facade;
		facade = nullptr;
	}
}

bool PlayerController::act() {

	if (GetAsyncKeyState((unsigned short)'W') & 0x8000) {
		inv->setCommand(commands[MOVEFWD]);
		inv->executeCommand();;
	}
	else if (GetAsyncKeyState((unsigned short)'S') & 0x8000) {
		inv->setCommand(commands[MOVEBWD]);
		inv->executeCommand();
	}

	inv->setCommand(commands[DISPLAY]);
	inv->executeCommand();

	if (GetAsyncKeyState((unsigned short)'D') & 0x8000) {
		inv->setCommand(commands[TURNRT]);
		inv->executeCommand();
	}
	else if (GetAsyncKeyState((unsigned short)'A') & 0x8000) {
		inv->setCommand(commands[TURNLT]);
		inv->executeCommand();
	}

	if (GetAsyncKeyState((unsigned short)'K') & 0x8000) {
		inv->setCommand(commands[ATTACK]);
		inv->executeCommand();
	}

	if (GetAsyncKeyState((unsigned short)'O') & 0x8000) {
		inv->setCommand(commands[SAVE]);
		inv->executeCommand();
	}
	else if (GetAsyncKeyState((unsigned short)'P') & 0x8000) {
		inv->setCommand(commands[LOAD]);
		inv->executeCommand();
	}

	if (GetAsyncKeyState((unsigned short)'Q') & 0x8000) {
		inv->setCommand(commands[EXIT]);
		inv->executeCommand();
	}
	system("cls");
	return facade->isRunning();
}