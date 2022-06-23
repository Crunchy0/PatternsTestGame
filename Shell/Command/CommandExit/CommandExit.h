#ifndef COMMANDEXIT
#define COMMANDEXIT

#include "..\Command.h"

class CommandExit :public Command {
private:
	Facade* reciever;
public:
	CommandExit(Facade* r);
	virtual void execute() override;
};

#endif