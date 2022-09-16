#include <iostream>
#include "GameStage.h"

int main() {
	
	GameStage gameStageHandler;
	
	gameStageHandler.Start();
	gameStageHandler.Update();
	gameStageHandler.GameOver();

	system("PAUSE");
	return 0;
}

