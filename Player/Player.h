#ifndef PLAYER
#define PLAYER

#include "..\Handler\Factory\Element\Element.h"
#include "..\Handler\Strategy\Strategies.h"
#include "..\Field\Field.h"

class Player {
private:
	double posX, posY;
	double dir[2];

	double thickness;
	int speed;
	int health;
	int score;

	Strategy* strategy;

	Player(double x, double y);
public:
	void operator+(const Element& e);
	friend ostream& operator<< (ostream& out, const Player& p);

	int getSpeed() const;
	int getHealth() const;
	int getScore() const;
	double getPosX() const;
	double getPosY() const;
	double getDirX() const;
	double getDirY() const;

	void setSpeed(int s);
	void setHealth(int h);
	void setScore(int sp);
	void setPos(double x, double y);
	void setDir(double x, double y);

	void setStrategy(int t);

	static Player& getInstance(double x, double y);
};

#endif