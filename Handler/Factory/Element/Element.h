#ifndef ELEMENT
#define ELEMENT

class Element {
public:
	virtual int getBonus() const = 0;
	virtual int getType() const = 0;
};

#endif