#include "Player.h"
#include <iostream>

Player::Player(double x, double y) {
	this->posX = x;
	this->posY = y;
	this->dir[0] = 0.0;
	this->dir[1] = 1.0;
	this->thickness = 0.1;
	this->speed = 30;
	this->health = 50;
	this->score = 0;
	this->alive = true;

	this->strategy = nullptr;
	setStrategy(1);
}

Player::~Player() {
	delete strategy;
}

void Player::operator+(const Element& e) {
	int type = e.getType();
	int bonus = e.getBonus();
	if(type == 0){
		setScore(score + strategy->interact(score, bonus));
	}
	else if (type == 1) {
		setHealth(health + strategy->interact(health, bonus));
	}
	else if (type == 2) {
		setSpeed(speed + strategy->interact(speed, bonus));
	}
}

ostream& operator<<(ostream& out, const Player& p) {
	out << "\nPlayer position : " << p.getPosX() << "  " << p.getPosY() << "\n";
	return out;
}

void Player::operator-(Entity& other) {
	other.setHealth(other.getHealth() - 10);
	if (other.getHealth() <= 0) other.kill();
}

int Player::getSpeed() const{
	return speed;
}
int Player::getHealth() const{
	return health;
}
int Player::getScore() const{
	return score;
}

double Player::getPosX() const {
	return posX;
}
double Player::getPosY() const {
	return posY;
}
double Player::getDirX() const {
	return dir[0];
}
double Player::getDirY() const {
	return dir[1];
}

void Player::setSpeed(int s) {
	speed = s;
}
void Player::setHealth(int h) {
	health = h;
}
void Player::setScore(int sp) {
	score = sp;
}

void Player::setPos(double x, double y) {
	posX = x;
	posY = y;
}
void Player::setDir(double x, double y) {
	dir[0] = x;
	dir[1] = y;
}

void Player::kill() {
	alive = false;
}

bool Player::isAlive() {
	return alive;
}
double Player::distance(const Entity& other) {
	double dist = sqrt(pow((other.getPosX() - getPosX()), 2) + pow((other.getPosY() - getPosY()), 2));
	return dist;
}
void Player::behave() {
	return;
}

void Player::setStrategy(int t) {
	if (strategy != nullptr) {
		delete strategy;
	}
	strategy = Strategy::chooseStrategy(t);
}

Player& Player::getInstance(double x, double y) {
	static Player player = Player(x, y);
	return player;
}