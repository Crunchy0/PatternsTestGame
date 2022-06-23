#ifndef FOUTPUT
#define FOUTPUT

#include "..\File\File.h"
#include "Output.h"

class FOutput :public Output {
private:
	File* file;
public:
	FOutput();
	~FOutput();
	virtual ostream& getOut() override;
	virtual void send(Subscriber *sub) override;
};

#endif