#ifndef PLAYERCONTROLLER
#define PLAYERCONTROLLER

#include "..\EntityController.h"
#include "..\..\Facade\Facade.h"
#include "..\..\Invoker\Invoker.h"

class PlayerController :public EntityController {
private:
	Command** commands;
	Invoker* inv;
	Facade* facade;

public:
	PlayerController(Handler* h);
	~PlayerController();

	bool act() override;
	void removeFacade();
};

#endif