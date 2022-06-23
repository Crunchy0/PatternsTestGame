#ifndef GUARD
#define GUARD

#include "..\..\..\Handler\Handler.h"

class Guard {
private:
	Field* field;
	Player* player;
	Entity* enemy;
public:
	Guard(Entity* e, Field* f, Player* p);
	void behave();
};

#endif