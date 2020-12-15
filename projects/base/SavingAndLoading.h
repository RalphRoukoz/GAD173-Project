#pragma once
#include "Tile.h"
#include "app.h"
#include <fstream>


class SavingAndLoading
{

public:
	 void Save(Tile* tiles, int length);
	 void Load();
	
};
