#ifndef PUBLISHER
#define PUBLISHER

#include "..\Sender\Outputs.h"
#include "..\Subscriber\Subscribers.h"

class Publisher {
private:
	Output* sender;
public:
	~Publisher();
	void addSender(Output* sub);
	Output* getSender();
	void removeSender();

	void alert(Subscriber* sub);
};

#endif