#pragma once
#include "SavingAndLoading.h"


void SavingAndLoading::Save(Tile* tiles, int lengthX, int lengthY)
{
	std::fstream MapLayout;
	MapLayout.open("Map.data");

		for (size_t i = 0; i < 70; i++)
		{
			MapLayout << tiles[i].id << ", ";

		}
	MapLayout.close();
}

void SavingAndLoading::Load() {

	std::string line;
	std::ifstream MapLayout("Map.data");

	if (MapLayout.is_open())
	{
		int ic = 0;
		std::getline(MapLayout, line);

		for (size_t i = 0; i <70; i++)
		{
			ic = line.find(',', ic + 1);
			std::string ss = line.substr(ic - 1, (line.find(',', ic + 1)) - ic - 2);
			std::cout << ss << std::endl;
		}	

		MapLayout.close();
	}	

	else
	{
		std::cout << "Unable to locate file";
	}			
};
