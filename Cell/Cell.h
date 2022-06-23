#ifndef CELL
#define CELL

#include "..\Handler\Factory\Factories.h"
#include "..\Log\Subscriber\Subscribers.h"

class Cell {
private:
	bool passable;
	int type;
	Element* content;
	Subscriber* sub;
public:
	Cell();
	~Cell();
	void setType(int x);
	int getType() const;
	void setContent(Element* e);
	Element* getContent() const;
	void addSub(Subscriber* s);
	void removeSub();
	Subscriber* getSub();
	void setPassable(bool a);
	bool isPassable() const;
};

#endif