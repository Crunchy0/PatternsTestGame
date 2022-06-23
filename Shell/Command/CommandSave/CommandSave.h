#ifndef COMMANDSAVE
#define COMMANDSAVE

#include "..\Command.h"

class CommandSave :public Command {
private:
	Facade* reciever;
public:
	CommandSave(Facade* r);
	virtual void execute() override;
};

#endif