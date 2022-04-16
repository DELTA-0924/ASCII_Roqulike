#include"Player.h"
Player::Player() {
	_x = 0;
	_y = 0;
}
void Player::init(int level, int health, int attack, int defence, int experience) {
	_health = health;
	_level = level;
	_attack = attack;
	_experience = experience;
	_defence = defence;
}
int Player::attack() {
	static default_random_engine randomEngine(time(NULL));
	uniform_int_distribution<int> attackROLL(0, _attack);
	return attackROLL(randomEngine);
}
void Player::setPosition(int x, int y) {
	_x = x;
	_y = y;
}
void Player::getPosition(int &x, int &y) {
	x = _x;
	y = _y;
}
void Player:: addExperience(int experience) {
	_experience += experience;
	while (_experience > 50) {
		printf("Ваш уровень повышен =%d\n", _level);
		_experience -= 50;
		_attack += 100;
		_defence += 70;
		_health += 20;
		_level++;
	}
	
}
int Player::takeDamage(int attack) {
	attack -= _defence;
	if (attack > 0) {
		_health -= attack;
		if (_health <= 0)
			return 1;
	}
	return 0;
}