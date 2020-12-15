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
		
		getline(MapLayout, line);
		int ic1 = line.find(',', 0);
		std::string ss1 = line.substr(0, ic1);
		int ic2 = line.find(',', ic1 + 1);
		std::string ss2 = line.substr(ic1 + 1, ic2 - ic1 - 1);
		int ic3 = line.find(',', ic2 + 1);
		std::string ss3 = line.substr(ic2 + 1, ic3 - ic2 - 1);

		std::cout << line << '\n';
		std::cout << ss3 << std::endl;
		MapLayout.close();
	}
	else {
		std::cout << "Unable to locate file";
	}
			
};
