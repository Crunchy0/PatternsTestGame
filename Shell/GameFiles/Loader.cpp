#include "Loader.h"

Loader::Loader() {
	this->f = nullptr;
	try {
		this->f = new File("savedgame.txt", 0);	
	}
	catch (int i) {
		throw i;
		delete this->f;
	}
}

Loader::~Loader() {
	delete f;
}

void Loader::load(Field& f, Player& p, Entity** en) {
	loadField(f);
	loadPlayer(p);
	loadEnemies(en, f, p);
}

void Loader::loadField(Field& f) {
	istream& file = this->f->getToRead();
	int width, height;
	int type, cont, bonus;
	bool passable;
	file >> height >> width;

	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			Cell& c = f.getCell(j, i);
			file >> passable >> type >> cont >> bonus;
			c.setPassable(passable);
			c.setType(type);
			switch (cont) {
			case 0:
				c.setContent(new Scorepoint(bonus));
				c.addSub(new ScorepointSub(bonus));
				break;
			case 1:
				c.setContent(new Healer(bonus));
				c.addSub(new HealerSub(bonus));
				break;
			case 2:
				c.setContent(new Booster(bonus));
				c.addSub(new BoosterSub(bonus));
				break;
			default:
				c.addSub(new EmptySub());
				c.setContent(nullptr);
			}
		}
	}
}

void Loader::loadEntity(Entity& e) {
	istream& file = f->getToRead();
	double x, y, dx, dy;
	int score, health, speed;
	file >> x >> y >> dx >> dy >> score >> health >> speed;
	e.setPos(x, y);
	e.setDir(dx, dy);
	e.setScore(score);
	e.setHealth(health);
	e.setSpeed(speed);
}

void Loader::loadPlayer(Player& p) {
	loadEntity(p);
}

void Loader::loadEnemies(Entity** e, Field& f, Player& p) {
	istream& file = this->f->getToRead();
	int num;
	bool exists;
	file >> num;
	for (int i = 0; i < num; i++) {
		file >> exists;
		if (exists) {
			if (e[i] != nullptr) {
				delete e[i];
			}
			switch (i)
			{
			case 0:
				e[i] = new Enemy<Guard>((4.5 + rand() % (f.getWidth() - 6) * 1.0), (4.5 + rand() % (f.getHeight() - 6) * 1.0), &f, &p);
				break;
			case 1:
				e[i] = new Enemy<Haunt>((4.5 + rand() % (f.getWidth() - 6) * 1.0), (4.5 + rand() % (f.getHeight() - 6) * 1.0), &f, &p);
				break;
			case 2:
				e[i] = new Enemy<Shoot>((4.5 + rand() % (f.getWidth() - 6) * 1.0), (4.5 + rand() % (f.getHeight() - 6) * 1.0), &f, &p);
				break;
			default:
				break;
			}
			loadEntity(*e[i]);
		}
		else if (e[i] != nullptr) {
			delete e[i];
			e[i] = nullptr;
		}
	}
}