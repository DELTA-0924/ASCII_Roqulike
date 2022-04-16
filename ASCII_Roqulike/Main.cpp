#include<iostream>
#include<stdlib.h>
#include<string>
#include<conio.h>
#include"GameSystem.h"
using namespace std;
int main() {
	GameSystem GameSystem("level1.txt");
	GameSystem.PlayGame();
	return 0;
}
