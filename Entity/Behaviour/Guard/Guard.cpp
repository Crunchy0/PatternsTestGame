#include "Guard.h"

Guard::Guard(Entity* e, Field* f, Player* p) {
	enemy = e;
	field = f;
	player = p;
}

void Guard::behave() {
	if (player->distance(*enemy) <= 2) *enemy - *player;
}