#include <ctime>
#include "Windows.h"
#include "Client.h"

Client::Client() {
	inv = new Invoker(nullptr);
	facade = new Facade(new Handler());
	commands = new Command * [7]{ new CommandFill(facade),
								new CommandMoveForward(facade),
								new CommandMoveBackward(facade),
								new CommandTurnLeft(facade),
								new CommandTurnRight(facade),
								new CommandDisplay(facade),
								new CommandExit(facade)};
}

Client::~Client() {
	removeFacade();
	delete inv;
	delete[] commands;
}

void Client::removeFacade() {
	if (facade != nullptr) {
		delete facade;
		facade = nullptr;
	}
}

enum Commands {
	FILL,
	MOVEFWD,
	MOVEBWD,
	TURNLT,
	TURNRT,
	DISPLAY,
	EXIT,
};

void Client::getInput() {
	srand((unsigned int)time(nullptr));
	inv->setCommand(commands[FILL]);
	inv->executeCommand();
	while (facade->isRunning()) {
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

		if (GetAsyncKeyState((unsigned short)'Q') & 0x8000) {
			inv->setCommand(commands[EXIT]);
			inv->executeCommand();
		}
		system("cls");
	}
	cout << "\n\n\n\t\t\tGAME OVER\n\n\n";
}