#pragma once
#include "Tile.h"
#include "app.h"
#include <fstream>

#define numberOfTilePerCol 4;
class SavingAndLoading
{
private:

public:
	 void Save(Tile* tiles, int length);
	 void Load();
};
