#include "GameStage.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "Input.h"
#include "Character.h"
#include "UI.h"
#include "randw.h"
#include "Inventory.h"
#include "Item.h"

GameStage::GameStage()
{
}

void GameStage::Start()
{
	levelLoc = "Levels/Level1.txt";
	chars = randw::Read(levelLoc, _line);

	playerS = randw::PositionOfChar(chars, _line, '@')[0];
	const int playerSpawn[2] = { playerS[0], playerS[1] };

	enemy1S = randw::PositionOfChar(chars, _line, 'E')[0];
	const int enemy1Spawn[2] = { enemy1S[0], enemy1S[1] };

	enemy2S = randw::PositionOfChar(chars, _line, 'E')[1];
	const int enemy2Spawn[2] = { enemy2S[0], enemy2S[1] };
	
	shopS = randw::PositionOfChar(chars, _line, 'x')[0];
	const int shopSpawn[2] = { shopS[0], shopS[1] };

	player.Init(playerSpawn, 5, "YOUR", 20);
	enemy1.Init(enemy1Spawn, 1, "E", 100);
	enemy2.Init(enemy2Spawn, 1, "E", 100);
	shop.Init(shopSpawn, 0, "SHOP");
	Item cards("cards", 5, 2);
	shop.inventory.AddItem(cards);
	shop.inventory.AddItem(cards);
	shop.inventory.AddItem(cards);
	shop.inventory.AddItem(cards);

	UI::UpdateUI(player, _line, chars, shop);
}

void GameStage::Update()
{
	while (levelLoop) {

		if (!player.OpenChest()) {
			dX = _input.X();
			dY = _input.Y();

			player.CharacterHandler(dX, dY, chars);

			enemy1.MoveCharacterAuto(e1dX, e1dY, chars, true, false);
			enemy2.MoveCharacterAuto(e2dX, e2dY, chars, false, true);

			UI::UpdateUI(player, _line, chars, shop);

			if (player.health <= 0) {
				levelLoop = false;
			}

			bool save = _input.Save();
			if (save) {
				randw::Save(chars, _line, levelLoc);
			}
		}
		else {
			if (shop.inventory.NumItems() > 0) {
				char yOrN;
				std::cin >> yOrN;
				if (yOrN == 'y') {
					player.buy = true;
					UI::UpdateUI(player, _line, chars, shop);
				}
				else if (yOrN == 'n') {
					player.buy = false;
					player.SetChest(false);
					UI::UpdateUI(player, _line, chars, shop);
				}
				if (player.buy) {
					int iNum;
					std::cin >> iNum;
					player.Buy(shop.inventory, iNum);
					player.buy = false;
					UI::UpdateUI(player, _line, chars, shop);
				}

			}
			else {
				player.SetChest(false);
			}
		}
	}
}

void GameStage::GameOver()
{
	std::cout << UI::GameOver() << std::endl;
}

