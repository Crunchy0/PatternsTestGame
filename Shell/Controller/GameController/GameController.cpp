#include "GameController.h"
#include <ctime>

GameController::GameController() {
	srand(time(nullptr));
	Handler* h = new Handler();
	controllers[0] = new PlayerController(h);
	controllers[1] = new EnemyController(h);
	curController = controllers[0];
	run();
	delete h;
}

GameController::~GameController() {
	for (int i = 0; i < 2; i++) {
		delete controllers[i];
	}
}

void GameController::setState(EntityController* c) {
	curController = c;
}

void GameController::run() {
	while (true) {
		setState(controllers[0]);
		if (!curController->act()) break;
		setState(controllers[1]);
		if (!curController->act()) break;
	}
}

GameController& GameController::getInstance() {
	static GameController instance = GameController();
	return instance;
}