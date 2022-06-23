#ifndef INVOKER
#define INVOKER

#include "..\Command\Commands.h"

class Invoker {
private:
	Command* command;
public:
	explicit Invoker(Command* c);
	~Invoker();
	void setCommand(Command* c);
	void removeCommand();
	void executeCommand();
};

#endif