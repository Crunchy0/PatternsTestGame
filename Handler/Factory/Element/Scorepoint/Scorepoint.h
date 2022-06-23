#ifndef SCOREPOINT
#define SCOREPOINT

#include "..\Element.h"

class Scorepoint : public Element {
private:
	int type;
	int points;
public:
	Scorepoint();
	virtual int getBonus() const override;
	virtual int getType() const override;
};

#endif