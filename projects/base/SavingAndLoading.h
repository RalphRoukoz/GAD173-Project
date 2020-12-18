#pragma once
#include "Tile.h"
#include "app.h"
#include <fstream>

class SavingAndLoading
{
private:

public:
	 void Save(Tile* tiles, int lengthX, int lengthY);
	 void Load();
};
