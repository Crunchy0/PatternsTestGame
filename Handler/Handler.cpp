#include "Handler.h"
#include <Windows.h>

#define N_ENEMIES 3

#define COS 0.9816
#define SIN 0.1736

using namespace std;

void Handler::fillWithElements() {
	struct Point {
		unsigned int x;
		unsigned int y;
	};

	Factory* fx[3] = { new ScorepointFactory(), new BoosterFactory(), new HealerFactory() };
	unsigned int passable = 0;

	for (unsigned int i = 1; i < f.getHeight() - 1; i++) {
		for (unsigned int j = 1; j < f.getWidth() - 1; j++) {
			if (f.getCell(j, i).isPassable()) {
				passable++;
			}
		}
	}
	if (passable) {
		unsigned int elements = (unsigned int)(passable * 0.18);
		if (!elements) {
			elements = 1;
		}

		Point* px = new Point[passable];
		passable = 0;
		for (unsigned int i = 1; i < f.getHeight() - 1; i++) {
			for (unsigned int j = 1; j < f.getWidth() - 1; j++) {
				if (f.getCell(j, i).isPassable()) {
					px[passable] = Point{ j, i };
					passable++;
				}
			}
		}
		Point targ;
		for (unsigned int i = 0; i < elements; i++) {
			unsigned int n = rand() % passable;
			unsigned int nfac = rand() % 3;
			targ.x = px[n].x;
			targ.y = px[n].y;
			for (unsigned int j = n; j < passable - 1; j++) {
				px[j].x = px[j + 1].x;
				px[j].y = px[j + 1].y;
			}
			passable--;

			Cell& chosen = f.getCell(targ.x, targ.y);
			chosen.setContent(fx[nfac]->createElement());
			int type = chosen.getContent()->getType();
			switch (type) {
			case 0:
				chosen.addSub(new ScorepointSub(chosen.getContent()->getBonus()));
				break;
			case 1:
				chosen.addSub(new HealerSub(chosen.getContent()->getBonus()));
				break;
			case 2:
				chosen.addSub(new BoosterSub(chosen.getContent()->getBonus()));
				break;
			default:
				chosen.addSub(new EmptySub());
			}
		}
	}
}

void Handler::moveF() {
	int newX = (int)(p.getPosX() + p.getDirX() * (p.getSpeed() / 100.0));
	int newY = (int)(p.getPosY() + p.getDirY() * (p.getSpeed() / 100.0));
	if (newX >= 0 && newX < f.getWidth() && f.getCell(newX, (int)p.getPosY()).isPassable()) {
		p.setPos(p.getPosX() + p.getDirX() * (p.getSpeed() / 100.0), p.getPosY());
	}
	if (newY >= 0 && newY < f.getHeight() && f.getCell((int)p.getPosX(), newY).isPassable()) {
		p.setPos(p.getPosX(), p.getPosY() + p.getDirY() * (p.getSpeed() / 100.0));
	}
}

void Handler::moveB() {
	int newX = (int)(p.getPosX() - p.getDirX() * (p.getSpeed() / 100.0));
	int newY = (int)(p.getPosY() - p.getDirY() * (p.getSpeed() / 100.0));
	if (newX >= 0 && newX < f.getWidth() && f.getCell(newX, (int)p.getPosY()).isPassable()) {
		p.setPos(p.getPosX() - p.getDirX() * (p.getSpeed() / 100.0), p.getPosY());
	}
	if (newY >= 0 && newY < f.getHeight() && f.getCell((int)p.getPosX(), newY).isPassable()) {
		p.setPos(p.getPosX(), p.getPosY() - p.getDirY() * (p.getSpeed() / 100.0));
	}
}

void Handler::interaction() {
	Cell& chosen = f.getCell((int)p.getPosX(), (int)p.getPosY());
	pub->getSender()->getOut() << p;
	if (chosen.getContent() != nullptr) {
		p + *chosen.getContent();
		pub->getSender()->getOut() << "Player interacts with ";
		pub->alert(chosen.getSub());
		chosen.setContent(nullptr);
		chosen.addSub(new EmptySub());
	}
	else {
		pub->alert(chosen.getSub());
	}
	if (f.getCell((int)p.getPosX(), (int)p.getPosY()).getType() == 3/* && p.getScore() > 3*/) {
		running = false;
	}
}

void Handler::attackEnemy() {
	Entity* en = getNearestEnemy();
	if (en != nullptr) {
		if (p.distance(*en) <= 2.5) {
			p - *en;
			for (int i = 0; i < N_ENEMIES; i++) {
				if (enemies[i] == en) {
					if (!en->isAlive()) {
						delete enemies[i];
						enemies[i] = nullptr;
					}
				}
			}
		}
	}
}

void Handler::turn(bool right) {
	double dx;
	double dy;
	if (right) {
		dx = COS * p.getDirX() - SIN * p.getDirY();
		dy = SIN * p.getDirX() + COS * p.getDirY();
	}
	else {
		dx = COS * p.getDirX() + SIN * p.getDirY();
		dy = -SIN * p.getDirX() + COS * p.getDirY();
	}
	static bool xy = false;
	int sx = dx > 0 ? 1 : -1;
	int sy = dy > 0 ? 1 : -1;
	while (dx * dx + dy * dy < 1.0) {
		if (xy) {
			dy += sy * 0.01;
			xy = false;
		}
		else {
			dx += sx * 0.01;
			xy = true;
		}
	}
	p.setDir(dx, dy);
}

void Handler::displayPlayerInfo() {
	std::cout << "Position : " << p.getPosX() << "   " << p.getPosY() << "\n";
	std::cout << "Health : " << p.getHealth() << "\n";
	std::cout << "Speed : " << p.getSpeed() << "\n";
	std::cout << "Score : " << p.getScore() << "\n";
}

void Handler::displayField() {
	for (unsigned int i = 0; i < f.getHeight(); i++) {
		for (unsigned int j = 0; j < f.getWidth(); j++) {
			Element* cur = f.getCell(j, i).getContent();
			if (cur != nullptr) {
				int type = cur->getType();
				if (type == 0) {
					cout << "{}";
				}
				else if (type == 1) {
					cout << "++";
				}
				else if (type == 2) {
					cout << "->";
				}
				continue;
			}
			if (f.getCell(j, i).getType() == 1) {
				cout << "X ";
			}
			else if (f.getCell(j, i).getType() == 2) {
				cout << "I ";
			}
			else if (f.getCell(j, i).getType() == 3) {
				cout << "O ";
			}
			else if (p.getPosX() - j >= 0.0 && p.getPosX() - j < 1.0 && p.getPosY() - i >= 0.0 && p.getPosY() - i < 1.0) {
				std::cout << "/\\";
			}
			else {
				bool here = false;
				for (int k = 0; k < N_ENEMIES; k++) {
					Entity* en = enemies[k];
					if (en == nullptr) {
						continue;
					}
					else if (en != nullptr && (en->getPosX() - j) >= 0.0 && (en->getPosX() - j) < 1.0 && (en->getPosY() - i) >= 0.0 && (en->getPosY() - i) < 1.0) {
						here = true;
						std::cout << "YY";
						break;
					}
					
				}
				if (!here) {
					cout << "  ";
				}
			}
		}
		cout << "\n";
	}
}

Handler::Handler() {
	running = true;
	pub = new Publisher();
	pub->addSender(new FOutput());
	enemies = new Entity * [N_ENEMIES];
	enemies[0] = createEnemy<Guard>();
	enemies[1] = createEnemy<Haunt>();
	enemies[2] = createEnemy<Shoot>();
}

template<class Behaviour>
Entity* Handler::createEnemy() {
	return new Enemy<Behaviour>((4.5 + rand() % (f.getWidth() - 6) * 1.0), (4.5 + rand() % (f.getHeight() - 6) * 1.0), &f, &p);
}

Handler::~Handler() {
	delete pub;
}

bool Handler::isRunning() {
	return running;
}

void Handler::exit() {
	running = false;
}

Entity* Handler::getNearestEnemy() {
	double minDist = sqrt(pow(f.getHeight(), 2) + pow(f.getWidth(), 2));
	Entity* nearest = nullptr;
	for (int i = 0; i < N_ENEMIES; i++) {
		if (enemies[i] != nullptr) {
			double curDist = p.distance(*enemies[i]);
			if (curDist < minDist) {
				minDist = curDist;
				nearest = enemies[i];
			}
		}
	}
	return nearest;
}

bool Handler::actEnemies() {
	Entity* en = nullptr;
	for (int i = 0; i < N_ENEMIES; i++) {
		en = enemies[i];
		if (en != nullptr) {
			en->behave();
			if (!p.isAlive()) {
				cout << "\n\n\n\t\t\tGAME OVER\n\n\n";
				exit();
				break;
			}
			else {
				displayField();
				system("cls");
			}
		}
	}
	
	return isRunning();
}

void Handler::save() {
	Saver* s = nullptr;
	try {
		s = new Saver();
		s->save(f, p, enemies, N_ENEMIES);
	}
	catch (int i) {
		cout << "\n\nUnable to create a file\n\n";
		Sleep(2000);
	}
	delete s;
}

void Handler::load() {
	Loader* l = nullptr;
	try {
		l = new Loader();
		l->load(f, p, enemies);
	}
	catch (int i) {
		if (!i) {
			cout << "\n\nUnable to load game: File does not exist\n\n";
		}
		else if (i == 1) {
			cout << "\n\nFile is empty\n\n";
		}
		Sleep(2000);
	}
	delete l;
}