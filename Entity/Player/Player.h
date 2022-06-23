#ifndef PLAYER
#define PLAYER

#include "..\..\Handler\Factory\Element\Element.h"
#include "..\..\Handler\Strategy\Strategies.h"
#include "..\..\Field\Field.h"
#include "..\Entity.h"

class Player: public Entity {
private:
	double posX, posY;
	double dir[2];

	double thickness;
	int speed;
	int health;
	int score;
	bool alive;

	Strategy* strategy;

	Player(double x, double y);
public:
	~Player();
	void operator+(const Element& e);
	friend ostream& operator<< (ostream& out, const Player& p);
	virtual void operator-(Entity& other) override;

	virtual int getSpeed() const override;
	virtual int getHealth() const override;
	virtual int getScore() const override;
	virtual double getPosX() const override;
	virtual double getPosY() const override;
	virtual double getDirX() const override;
	virtual double getDirY() const override;

	virtual void setSpeed(int s) override;
	virtual void setHealth(int h) override;
	virtual void setScore(int sp) override;
	virtual void setPos(double x, double y) override;
	virtual void setDir(double x, double y) override;

	virtual bool isAlive() override;
	virtual void kill() override;
	virtual double distance(const Entity& other) override;
	virtual void behave() override;

	void setStrategy(int t);

	static Player& getInstance(double x, double y);
};

#endif