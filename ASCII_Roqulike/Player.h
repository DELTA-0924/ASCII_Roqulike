#pragma once
#include<random>
#include<ctime>
using namespace std;
class Player{
public:
	Player();
	void init(int level,int health,int attack,int defence,int experience);
	int attack();
	//Принимающиe позиции
	void  getPosition(int &x, int &y);
	//Изменение позиций
	void  setPosition(int x,int y);
	void addExperience(int experience);
	int takeDamage(int attack);
private:
	//Характеристики 
	int _health;
	int _attack;
	int _defence;
	int _experience;
	int _level;
	//Позиции
	int _x;
	int _y;

};