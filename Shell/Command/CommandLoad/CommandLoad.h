#ifndef COMMANDLOAD
#define COMMANDLOAD

#include "..\Command.h"

class CommandLoad :public Command {
private:
	Facade* reciever;
public:
	CommandLoad(Facade* r);
	virtual void execute() override;
};

#endif