#ifndef SHOOT
#define SHOOT

#include "..\..\..\Handler\Handler.h"

class Shoot {
private:
	Field* field;
	Player* player;
	Entity* enemy;
public:
	Shoot(Entity* e, Field* f, Player* p);
	void behave();
};

#endif