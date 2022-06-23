#include "Saver.h"

Saver::Saver() {
	this->f = nullptr;
	try {
		this->f = new File("savedgame.txt", 1);
	}
	catch (int i) {
		throw i;
		delete this->f;
	}
}

Saver::~Saver() {
	delete this->f;
}

void Saver::save(Field& f, Player& p, Entity** en, int n) {
	saveField(f);
	savePlayer(p);
	saveEnemies(en, n);
}

void Saver::saveField(Field& f) {
	ostream& file = this->f->getToWrite();
	file << f.getHeight() << " " << f.getWidth() << "\n";
	for (int i = 0; i < f.getHeight(); i++) {
		for (int j = 0; j < f.getWidth(); j++) {
			Cell& c = f.getCell(j, i);
			file << c.isPassable() << " " << c.getType() << " ";
			Element* e = c.getContent();
			if (e != nullptr) {
				file << e->getType() << " " << e->getBonus() << " ";
			}
			else {
				file << -1 << " " << 0 << " ";
			}
		}
		file << "\n";
	}
}

void Saver::saveEntity(Entity& e) {
	ostream& file = this->f->getToWrite();
	file << e.getPosX() << " " << e.getPosY() << " " << e.getDirX() << " " << e.getDirY() << " " << e.getScore() << " " << e.getHealth() << " " << e.getSpeed() << "\n";
}

void Saver::savePlayer(Player& p) {
	saveEntity(p);
}

void Saver::saveEnemies(Entity** e, int n) {
	ostream& file = this->f->getToWrite();
	file << n << "\n";
	for (int i = 0; i < n; i++) {
		if (e[i] != nullptr) {
			file << 1 << " ";
			saveEntity(*e[i]);
		}
		else {
			file << 0 << "\n";
		}
	}
}