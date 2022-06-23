#include "Haunt.h"

Haunt::Haunt(Entity* e, Field* f, Player* p) {
	enemy = e;
	field = f;
	player = p;
}

void Haunt::behave() {
	double dist = player->distance(*enemy);
	if (dist <= 3.5 && dist > 1.0) {
		enemy->setDir(- ((enemy->getPosX() - player->getPosX())) / dist, - (enemy->getPosY() - player->getPosY()) / dist);
		int newX = (int)(enemy->getPosX() + enemy->getDirX() * (enemy->getSpeed() / 100.0));
		int newY = (int)(enemy->getPosY() + enemy->getDirY() * (enemy->getSpeed() / 100.0));
		if (newX >= 0 && newX < field->getWidth() && field->getCell(newX, (int)enemy->getPosY()).isPassable()) {
			enemy->setPos(enemy->getPosX() + enemy->getDirX() * (enemy->getSpeed() / 100.0), enemy->getPosY());
		}
		if (newY >= 0 && newY < field->getHeight() && field->getCell((int)enemy->getPosX(), newY).isPassable()) {
			enemy->setPos(enemy->getPosX(), enemy->getPosY() + enemy->getDirY() * (enemy->getSpeed() / 100.0));
		}
	}
	if (dist <= 2) {
		*enemy - *player;
	}
}