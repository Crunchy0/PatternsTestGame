#ifndef HANDLER
#define HANDLER

#include "..\Shell\GameFiles\Loader.h"
#include "..\Shell\GameFiles\Saver.h"
#include "..\Log\Publisher\Publisher.h"
#include "..\Entity\Entities.h"
#include "..\Entity\Behaviour\Behaviours.h"

class Handler {
private:
	Field& f = Field::getInstance(17, 21);
	Player& p = Player::getInstance(1.5, 0.5);
	Entity** enemies;
	Publisher* pub;
	bool running;
public:
	Handler();
	~Handler();
	Entity* getNearestEnemy();

	template<class Behaviour> Entity* createEnemy();
	bool actEnemies();
	void moveF();
	void moveB();
	void interaction();
	void attackEnemy();
	void turn(bool right);
	void displayPlayerInfo();
	void displayField();
	void save();
	void load();
	void fillWithElements();
	bool isRunning();
	void exit();

};

#endif
