#ifndef COMMANDTURNRIGHT
#define COMMANDTURNRIGHT

#include "..\Command.h"

class CommandTurnRight :public Command {
private:
	Facade* reciever;
public:
	CommandTurnRight(Facade* r);
	virtual void execute() override;
};

#endif