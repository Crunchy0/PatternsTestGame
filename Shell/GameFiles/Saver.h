#ifndef SAVER
#define SAVER

#include "..\..\Log\File\File.h"
#include "..\..\Field\Field.h"
#include "..\..\Entity\Entities.h"

class Saver {
private:
	File* f;
public:
	Saver();
	~Saver();
	void save(Field& f, Player& p, Entity** en, int n);
	void saveField(Field& f);
	void saveEntity(Entity& e);
	void savePlayer(Player& p);
	void saveEnemies(Entity** e, int n);
};

#endif