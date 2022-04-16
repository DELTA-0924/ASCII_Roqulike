#pragma once
#include<random>
#include<ctime>
using namespace std;
class Player{
public:
	Player();
	void init(int level,int health,int attack,int defence,int experience);
	int attack();
	//����������e �������
	void  getPosition(int &x, int &y);
	//��������� �������
	void  setPosition(int x,int y);
	void addExperience(int experience);
	int takeDamage(int attack);
private:
	//�������������� 
	int _health;
	int _attack;
	int _defence;
	int _experience;
	int _level;
	//�������
	int _x;
	int _y;

};