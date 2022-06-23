#ifndef HEALER
#define HEALER

#include "..\Element.h"

class Healer : public Element {
private:
	int type;
	int hp;
public:
	Healer();
	virtual int getBonus() const override;
	virtual int getType() const override;
};

#endif