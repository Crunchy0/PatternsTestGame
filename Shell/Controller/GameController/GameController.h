#ifndef GAMECONTROLLER
#define GAMECONTROLLER

#include "..\EnemyController\EnemyController.h"
#include "..\PlayerController\PlayerController.h"

class GameController {
private:
	EntityController* controllers[2];
	EntityController* curController;
	GameController();
public:
	~GameController();
	void setState(EntityController* c);
	void run();
	static GameController& getInstance();
};

#endif