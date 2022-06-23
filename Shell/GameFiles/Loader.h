#ifndef LOADER
#define LOADER

#include "..\..\Log\File\File.h"
#include "..\..\Field\Field.h"
#include "..\..\Entity\Entities.h"

class Loader {
private:
	File* f;
public:
	Loader();
	~Loader();
	void load(Field& f, Player& p, Entity** en);
	void loadField(Field& f);
	void loadEntity(Entity& e);
	void loadPlayer(Player& p);
	void loadEnemies(Entity** e, Field& f, Player& p);
};

#endif