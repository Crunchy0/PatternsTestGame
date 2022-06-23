#ifndef COMMANDMOVEBACKWARD
#define COMMANDMOVEBACKWARD

#include "..\Command.h"

class CommandMoveBackward :public Command {
private:
	Facade* reciever;
public:
	CommandMoveBackward(Facade* r);
	virtual void execute() override;
};

#endif