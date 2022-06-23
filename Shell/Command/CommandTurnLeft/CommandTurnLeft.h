#ifndef COMMANDTURNLEFT
#define COMMANDTURNLEFT

#include "..\Command.h"

class CommandTurnLeft :public Command {
private:
	Facade* reciever;
public:
	CommandTurnLeft(Facade* r);
	virtual void execute() override;
};

#endif