#include "Publisher.h"

Publisher::~Publisher() {
	removeSender();
}

void Publisher::addSender(Output* output) {
	removeSender();
	sender = output;
}

Output* Publisher::getSender() {
	return sender;
}

void Publisher::removeSender() {
	if (sender != nullptr) {
		delete sender;
		sender = nullptr;
	}
}

void Publisher::alert(Subscriber* sub) {
	sender->send(sub);
}