#ifndef FACADE
#define FACADE

#include "..\..\Handler\Handler.h"

class Facade {
private:
	Handler* handler;
public:
	explicit Facade(Handler* h);
	void save();
	void load();
	bool isRunning();
	void fill();
	void turn(bool right);
	void move(bool forward);
	void attackEnemies();
	void display();
	void exit();
};

#endif