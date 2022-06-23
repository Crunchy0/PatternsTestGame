#include "Cell.h"

	Cell::Cell() {
		this->passable = true;
		this->type = 0;
		this->content = nullptr;
		this->sub = nullptr;
	}

	Cell::~Cell() {
		delete content;
	}

	void Cell::setType(int x) {
		this->type = x;
	}
	int Cell::getType() const {
		return this->type;
	}

	void Cell::setContent(Element* e) {
		if (content != nullptr) {
			delete content;
		}
		content = e;
	}
	Element* Cell::getContent() const {
		return content;
	}

	void Cell::addSub(Subscriber* s) {
		removeSub();
		sub = s;
	}

	void Cell ::removeSub() {
		if (sub != nullptr) {
			delete sub;
			sub = nullptr;
		}
	}

	Subscriber* Cell::getSub() {
		return sub;
	}

	void Cell::setPassable(bool a) {
		this->passable = a;
	}
	bool Cell::isPassable() const {
		return this->passable;
	}