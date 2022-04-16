#pragma once
#include"Player.h"
#include"Level.h"
#include<fstream>
#include<string>
#include<iostream>
#include<conio.h>
#include<windows.h>
#include"Enemy.h"
using namespace std;
class GameSystem 
{
public:

	GameSystem(string levelfileName);
	void PlayGame();
	void playerMove();
	private:
		Level _level;
		Player _player;
};