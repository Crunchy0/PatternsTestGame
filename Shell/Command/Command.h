#ifndef COMMAND
#define COMMAND

#include "..\Facade\Facade.h"

class Command {
public:
	virtual void execute() = 0;
};

#endif