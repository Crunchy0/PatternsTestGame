#ifndef HAUNT
#define HAUNT

#include "..\..\..\Handler\Handler.h"

class Haunt {
private:
	Field* field;
	Player* player;
	Entity* enemy;
public:
	Haunt(Entity* e, Field* f, Player* p);
	void behave();
};

#endif