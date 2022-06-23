#ifndef ENEMY
#define ENEMY

#include "..\Entity.h"
#include "..\..\Handler\Handler.h"

template<class Behaviour>
class Enemy : public Entity {
private:
	double posX, posY;
	double dir[2];

	double thickness;
	int speed;
	int health;
	int score;
	bool alive;

	Behaviour* behaviour;
	
public:
	Enemy(double x, double y, Field* f, Player* p) {
		this->posX = x;
		this->posY = y;
		this->dir[0] = 0.0;
		this->dir[1] = 1.0;
		this->thickness = 0.1;
		this->speed = 10;
		this->health = 15;
		this->score = 0;
		this->alive = true;
		behaviour = new Behaviour(this, f, p);
	}

	~Enemy() {
		delete behaviour;
	}

	virtual void operator-(Entity& other) override {
		other.setHealth(other.getHealth() - 1);
		if (other.getHealth() <= 0) other.kill();
	}

	int getSpeed() const {
		return speed;
	}
	int getHealth() const {
		return health;
	}
	int getScore() const {
		return score;
	}

	double getPosX() const {
		return posX;
	}
	double getPosY() const {
		return posY;
	}
	double getDirX() const {
		return dir[0];
	}
	double getDirY() const {
		return dir[1];
	}

	void setSpeed(int s) {
		speed = s;
	}
	void setHealth(int h) {
		health = h;
	}
	void setScore(int sp) {
		score = sp;
	}

	void setPos(double x, double y) {
		posX = x;
		posY = y;
	}
	void setDir(double x, double y) {
		dir[0] = x;
		dir[1] = y;
	}

	virtual void kill() override {
		alive = false;
	}

	virtual bool isAlive() override {
		return this->alive;
	}

	virtual double distance(const Entity& other) override {
		return sqrt(pow(posX - other.getPosX(), 2) + pow(posY - other.getPosY(), 2));
	}

	virtual void behave() override {
		behaviour->behave();
	}
};

#endif