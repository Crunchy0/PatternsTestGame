#ifndef CLIENT
#define CLIENT

#include "..\Facade\Facade.h"
#include "..\Invoker\Invoker.h"

class Client {
private:
	Command** commands;
	Invoker* inv;
	Facade* facade;

public:
	Client();
	~Client();

	void getInput();
	void removeFacade();
};

#endif