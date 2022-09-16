#pragma once
#include <vector>
#include "Character.h"
#include "Input.h"

class GameStage
{
public:
	GameStage();
	void Start();
	void Update();
	void GameOver();

private:
	//Level vars
	Input _input;
	int _line = 0;
	std::vector<std::vector<char>> chars;
	std::string levelLoc = "";
	//player vars
	std::vector<int> playerS;
	Character player;
	int dX = 0;
	int dY = 0;
	//enemy vars
	std::vector<int> enemy1S;
	Character enemy1;
	int e1dX = 1;
	int e1dY = 0;
	std::vector<int> enemy2S;
	Character enemy2;
	int e2dX = 0;
	int e2dY = 1;
	//Shop
	std::vector<int> shopS;
	Character shop;
	bool levelLoop = true;
};

