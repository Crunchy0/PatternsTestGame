#ifndef COMMANDFILL
#define COMMANDFILL

#include "..\Command.h"

class CommandFill :public Command {
private:
	Facade* reciever;
public:
	CommandFill(Facade* r);
	virtual void execute() override;
};

#endif