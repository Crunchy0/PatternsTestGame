#ifndef COMMANDDISPLAY
#define COMMANDDISPLAY

#include "..\Command.h"

class CommandDisplay :public Command {
private:
	Facade* reciever;
public:
	CommandDisplay(Facade* r);
	virtual void execute() override;
};

#endif