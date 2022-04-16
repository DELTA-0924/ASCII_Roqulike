#include "Enemy.h"
Enemy::Enemy(string name, char tile, int level, int attack, int defence, int health, int xp) {
	_name = name;
	_level = level;
	_attack = attack;
	_health = health;
	_defence = defence;
	_experienceValue = xp;
	_tile = tile;
}
int Enemy::attack() {
	static default_random_engine randomEngine(time(NULL));
	uniform_int_distribution<int> attackROLL(0, _attack);
	return attackROLL(randomEngine);
}
void Enemy::setPosition(int x, int y) {
	_x = x;
	_y = y;
}
void Enemy::getPosition(int& x, int& y) {
	x = _x;
	y = _y;
}
int Enemy::takeDamage(int attack) {
	attack -= _defence;
	if (attack > 0) {
		_health -= attack;
		if (_health <= 0)
			return _experienceValue;
	}
	return 0;
}