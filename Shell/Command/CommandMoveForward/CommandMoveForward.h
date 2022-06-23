#ifndef COMMANDMOVEFORWARD
#define COMMANDMOVEFORWARD

#include "..\Command.h"

class CommandMoveForward :public Command {
private:
	Facade* reciever;
public:
	CommandMoveForward(Facade* r);
	virtual void execute() override;
};

#endif