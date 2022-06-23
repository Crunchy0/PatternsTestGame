#include "EnemyController.h"

EnemyController::EnemyController(Handler* h) {
	handler = h;
}

bool EnemyController::act() {
	return handler->actEnemies();
}