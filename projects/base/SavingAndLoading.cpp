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
	if (MapLayout.is_open())
	{
		std::getline(MapLayout, line);
		for (size_t i = 0; i < 6; i++)
		{
			int ic1 = line.find(',', 0);
			std::string ss1 = line.substr(0, ic1);
			int ic2 = line.find(',', ic1 + 1);
			std::string ss2 = line.substr(ic1 + 1, ic2 - ic1 - 1);
			int ic3 = line.find(',', ic2 + 1);
			std::string ss3 = line.substr(ic2 + 1, ic3 - ic2 - 1);
			int ic4 = line.find(',', ic3 + 1);
			std::string ss4 = line.substr(ic3 + 1, ic4 - ic3 - 1);
			int ic5 = line.find(',', ic4 + 1);
			std::string ss5 = line.substr(ic4 + 1, ic5 - ic4 - 1);
			int ic6 = line.find(',', ic5 + 1);
			std::string ss6 = line.substr(ic5 + 1, ic6 - ic5 - 1);
			std::cout << ss1 << std::endl;
			std::cout << ss2 << std::endl;
			std::cout << ss3 << std::endl;
			std::cout << ss4 << std::endl;
			std::cout << ss5 << std::endl;
			std::cout << ss6 << std::endl;
			i++;
			
		}
				

		MapLayout.close();
	}
	else {
		std::cout << "Unable to locate file";
	}
			
};
