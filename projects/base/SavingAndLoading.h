#pragma once
#include "Tile.h"
#include "app.h"
#include <fstream>


class SavingAndLoading
{
	private:
		std::string ss;
		int Newss;
	public:
	 void Save(Tile* tiles, int length);
	 void Load(Tile* tiles, int length, std::vector<sf::Sprite> Sprites, sf::Sprite TileSprites, sf::Texture* RedTile);
};
