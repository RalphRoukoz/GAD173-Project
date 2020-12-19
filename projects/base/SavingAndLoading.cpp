#pragma once
#include "SavingAndLoading.h"


void SavingAndLoading::Save(Tile* tiles, int length)
{
	std::fstream MapLayout;
	MapLayout.open("Map.data");

		for (size_t i = 0; i < length; i++)
		{
			MapLayout << tiles[i].id << ", ";

		}
	MapLayout.close();
}

void SavingAndLoading::Load(Tile* tiles, int length, std::vector<sf::Sprite> Sprites, sf::Sprite TileSprites, sf::Texture* RedTile)
{

	std::string line;
	std::ifstream MapLayout("Map.data");

	if (MapLayout.is_open())
	{
		int ic = 0;
		std::getline(MapLayout, line);

		while (std::getline(MapLayout, line))
		{
			ic = line.find(',', ic + 1);
			ss = line.substr(ic - 1, (line.find(',', ic + 1)) - ic - 2);
			Newss = stoi(ss);
			std::cout << std::stoi(ss) << std::endl;		
		}
		MapLayout.close();
	}
	
	else
	{
		std::cout << "Unable to locate file";
	}	

};

