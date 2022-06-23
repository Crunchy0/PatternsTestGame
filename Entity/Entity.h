#ifndef ENTITY
#define ENTITY

class Entity {
public:
	virtual void operator-(Entity& other) = 0;
	virtual int getSpeed() const = 0;
	virtual int getHealth() const = 0;
	virtual int getScore() const = 0;
	virtual double getPosX() const = 0;
	virtual double getPosY() const = 0;
	virtual double getDirX() const = 0;
	virtual double getDirY() const = 0;
	virtual void setSpeed(int s) = 0;
	virtual void setHealth(int h) = 0;
	virtual void setScore(int sp) = 0;
	virtual void setPos(double x, double y) = 0;
	virtual void setDir(double x, double y) = 0;
	virtual void kill() = 0;
	virtual bool isAlive() = 0;
	virtual double distance(const Entity& other) = 0;
	virtual void behave() = 0;
};

#endif