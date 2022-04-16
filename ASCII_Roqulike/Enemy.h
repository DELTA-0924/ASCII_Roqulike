#pragma once
#include<iostream>
#include<random>
#include<ctime>
using namespace std;
class Enemy
{
public:
	int attack();
	//Принимающиe позиции
	void  getPosition(int& x, int& y);
	//Изменение позиций
	void  setPosition(int x, int y);
	Enemy(string name,char tile,int level,int attack,int defence,int health,int xp);
	string getname() { return _name; }
	int takeDamage(int attack);
private:
	string _name;
	char _tile;
	int _attack;
	int _defence;
	int _health;
	int _level;
	int _experienceValue;
	//Позиции
	int _x;
	int _y;

};

