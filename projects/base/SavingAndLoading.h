#pragma once
#include "Tile.h"
#include "app.h"
#include <fstream>

#define numberOfTilePerCol 4;
class SavingAndLoading
{
private:
	int ic[4];
	std::string ss[4];
public:
	 void Save(Tile* tiles, int length);
	 void Load();
};
