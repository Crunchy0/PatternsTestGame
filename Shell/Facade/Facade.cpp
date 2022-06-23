#include "Facade.h"

Facade::Facade(Handler* h) {
	handler = h;
}

void Facade::save() {
	handler->save();
}

void Facade::load() {
	handler->load();
}

bool Facade::isRunning() {
	return handler->isRunning();
}

void Facade::fill() {
	handler->fillWithElements();
}

void Facade::turn(bool right) {
	handler->turn(right);
}

void Facade::move(bool forward) {
	if (forward) {
		handler->moveF();
	}
	else {
		handler->moveB();
	}
	handler->interaction();
}

void Facade::attackEnemies() {
	handler->attackEnemy();
}

void Facade::display() {
	handler->displayField();
	handler->displayPlayerInfo();
}

void Facade::exit() {
	handler->exit();
}