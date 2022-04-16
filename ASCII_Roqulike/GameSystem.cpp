#include"GameSystem.h"

GameSystem::GameSystem(string levelfileName) {
	_player.init(1,100,50,50,0);
	_level.Load(levelfileName,_player);
	
	system("pause");
}

	
void GameSystem::PlayGame() {
	bool isDone = false;
	while (isDone != true) {
			_level.print();
			playerMove();
	}
}
void GameSystem::playerMove() {
	setlocale(LC_CTYPE, "RUSSIAN");
	char input;
	cout << "¬ведите команды дл€ движение: (w/a/s/d)";	
	input = _getch();
	if (GetAsyncKeyState(0x1B)) { exit(1); }
	_level.movePlayer(input,_player);
}
