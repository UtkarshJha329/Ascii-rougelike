#include "UI.h"

#include <stdio.h>

#include <iostream>
#include <string>
#include <vector>
#include "Character.h"
#include "Inventory.h"

UI::UI()
{
}

void UI::UpdateUI(Character& character, const int linesInLvl, const std::vector<std::vector<char>>& chars, Character& shop)
{
	system("CLS");
	for (int i = 0; i < linesInLvl; i++) {
		for (int j = 0; j < chars[i].size(); j++) {
			std::cout << chars[i][j];
		}

		if (!character.OpenChest()) {
			NormalUI(i, GetHearts(character.health), character.Money(), character.health);
		}
		else {
			ShopUI(i, shop, character);
		}

		if (i == linesInLvl - 1 && character.OpenChest() == true) {
			if(character.buy){
				std::cout << "            Item number to buy: ";
			}
			else {
				if (shop.inventory.NumItems() > 0) {
					std::cout << "            Want to buy(y/n): ";
				}
				else {
					std::cout << "Emptied Out!";
				}
			}
		}
		else {
			std::cout << std::endl;
		}
	}
}

void UI::NormalUI(const int i, const std::string health, const int money, const int hearts)
{
	switch(i)
	{
	case 5:
		std::cout << "         ______INFO_____";
		break;
	case 6:
		std::cout << "         |" << "Hearts: "<< " " << health << "|";
		break;
	case 7: 
		std::cout << "         |" << "Money : " << " " << money << "   |";
		break;
	}
}

void UI::ShopUI(const int i, Character& shop, Character& player)
{
	if (i == 4) {
		std::cout << "                   " << player.inventory.Name() << " MONEY: " << player.Money();
	}
	if (i == 5) {
		std::cout << "         ______" << shop.inventory.Name() <<"_____" << "  ______" << player.inventory.Name() << "_____";
	}
	else if (i > 5) {
		if (shop.inventory.NumItems() >= 0) {

			if (shop.inventory.NumItems() > 0) {
				for (int e = 0; e < shop.inventory.NumItems(); e++)
				{
					if (i == 6 + e) {
						std::cout << "         |" << e << ") " << shop.inventory.ItemAtIndex(e).Name() << "  X" << shop.inventory.ItemAtIndex(e).Count() << " |";
					}
				}
			}
			else {
				std::cout << "                        ";
			}
			for (int e = 0; e < player.inventory.NumItems(); e++)
			{
				if (i == 6 + e) {
					std::cout << "  |" << e << ") " << player.inventory.ItemAtIndex(e).Name() << "  X" << player.inventory.ItemAtIndex(e).Count() << " |";
				}
			}
		}
	}
	else {

	}
}

std::string UI::GetHearts(int health) {
	std::string hearts = "";
	if (health != 0) {
		for (int i = 0; i < health; i++)
		{
			hearts += "*";
			if (health < 5 && i == health - 1) {
				for (int j = 0; j < 5 - health; j++)
				{
					hearts += " ";
				}
			}
		}
	}
	else {
		hearts = "     ";
	}
	return hearts;
}

std::string UI::GameOver()
{
	return "\n\nHealth Depleted - X-X-X-X-X \n            GAME OVER";
}

