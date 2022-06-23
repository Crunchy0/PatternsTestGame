#ifndef COMMANDATTACK
#define COMMANDATTACK

#include "..\Command.h"

class CommandAttack :public Command {
private:
	Facade* reciever;
public:
	CommandAttack(Facade* r);
	virtual void execute() override;
};

#endif