#include "Level.h"
#include<fstream>
#include<iostream>
#include<cstdio>
Level::Level() {}
void Level::Load(string fileName, Player& player) {
	ifstream file;
	file.open(fileName);
	if (file.fail()) {
		perror(fileName.c_str());
		system("pause");
		exit(1);
	}
	string line;
	while (getline(file, line)) {
		_levelData.push_back(line);
	}
	file.close();
	//������� ����
	char tile;
	for (int i = 0; i <   _levelData.size(); i++) {
		for (int j = 0; j < _levelData[i].size(); j++) {
			tile = _levelData[i][j];
			switch(tile){
			case '@':
				player.setPosition(j, i);
				break;
			case 'S'://����
				_enemies.push_back(Enemy("Snake",tile,10,30,10,100,500));
				_enemies.back().setPosition(j, i);
					break;
				case 'g'://������
					_enemies.push_back(Enemy("Goblin", tile, 20, 50, 20, 150, 1500));
					_enemies.back().setPosition(j, i);
					break;
				case 'O'://���
					_enemies.push_back(Enemy("Ogre", tile, 40, 100, 10, 50, 2000));
					_enemies.back().setPosition(j, i);
					break;
				case 'B'://������
					_enemies.push_back(Enemy("Bandit", tile, 50, 800, 500, 102, 2050));
					_enemies.back().setPosition(j, i);
					break;
				case 'D'://������
					_enemies.push_back(Enemy("Dragon", tile, 100, 15, 100000000, 20000000, 1000));
					_enemies.back().setPosition(j, i);
					break;
			}
		}
	}
	
}
void  Level::print() {
	cout << string(100, '\n');
	for (int i = 0; i < _levelData.size(); i++) {
		printf("%s\n", _levelData[i].c_str());
	}
	printf("\n");
}
void Level::movePlayer(char input ,Player &player) {
	setlocale(LC_CTYPE, "RUSSIAN");
	int playerX, playerY;
	player.getPosition(playerX, playerY);
	switch (input) {
	case 'w'://�����
	case 'W':
		processPlayerMove(player,playerX, playerY - 1);
		break;
	case'a':
	case 'A'://����
		processPlayerMove(player, playerX-1, playerY);
		break;
	case 's'://����
	case 'S':
		processPlayerMove(player, playerX, playerY+1);
		break;
	case 'd'://������
	case 'D':
		processPlayerMove(player, playerX+1, playerY);
		break;
	default:
	
		printf("�������� ����");
		system("pause");
		break;
	}
}
	char Level::getTile(int x,int y) {
		return _levelData[y][x];
		
	}
	void Level::setTile(int x, int y, char tile) {
		_levelData[y][x] = tile;
	}
	void Level::processPlayerMove(Player& player, int targetX, int targetY) {
		setlocale(LC_CTYPE, "RUSSIAN");
		int playerX;
		int playerY;
		player.getPosition(playerX, playerY);

		char moveTile = getTile(targetX, targetY);
		switch (moveTile) {
		case '.':
			player.setPosition(targetX, targetY);
			setTile(playerX, playerY, '.');
			setTile(targetX, targetY, '@');
			break;  
		case '#':
			break;
		default:
			battleMonster(player, targetX, targetY);
		}
	}
	void Level::battleMonster(Player& player, int targetX, int targetY) {
		int enemyX;
		int enemyY;
		int attackRoll;
		int attackResult;
		int playerX;
		int playerY;
		player.getPosition(playerX, playerY);
		string Enemyname;
		for (int i = 0; i < _enemies.size(); i++) {
			_enemies[i].getPosition(enemyX, enemyY);
			Enemyname=_enemies[i].getname();
			if (targetX == enemyX && targetY == enemyY) {
				attackRoll = player.attack();
				printf("�� �������� %s � ����� =%d\n",Enemyname.c_str(), attackRoll);
				
				attackResult = _enemies[i].takeDamage(attackRoll);
				if (attackResult != 0) {
					setTile(targetX, targetY, '.');
					printf("���������!!!\n");
					system("pause");
					player.addExperience(attackResult);
					
					return;
				}
				attackRoll = _enemies[i].attack();
				printf("��� ������� %s �  ����� =%d\n", Enemyname.c_str(), attackRoll);
			
				attackResult = player.takeDamage(attackRoll);
				if (attackResult != 0) {
					setTile(playerX, playerY, 'X');
					print();
					printf(" �����  ���������!!!\n");
					system("pause");
					exit(0);
					return;
				}
				system("pause");
				return;
			}
		}
	}