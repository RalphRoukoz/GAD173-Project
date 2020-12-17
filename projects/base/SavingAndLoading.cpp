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

void SavingAndLoading::Load() {

	std::string line;
	std::ifstream MapLayout("map.data");
	if (MapLayout.is_open()) {
		for (size_t i = 0; i < 4; i++)
		{
			for (size_t i = 0; i < 4; i++)
			{
				getline(MapLayout, line);
				ic[i] = line.find(',', 0);
				ss[i] = line.substr(0, ic[i]);
			}			
		}		
		std::cout << line << '\n';
		std::cout << ic[0] << std::endl;
		std::cout << ic[1] << std::endl;
		std::cout << ic[2] << std::endl;
		std::cout << ic[3] << std::endl;
		MapLayout.close();
	}
	else {
		std::cout << "Unable to locate file";
	}
			
};
