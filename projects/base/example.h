#pragma once

#include "app.h"
#include <vector>
#include <fstream>
#include <iostream>
#include <string>
#include "Tile.h"
#include "SavingAndLoading.h"


#define LineThickness 2

#define CellHeight 90
#define CellWidth 270

#define GridOffSetX 0 
#define GridOffSetY 0

#define TotalCellsX 6+ 1
#define TotalCellsY 10 + 1

#define TilesArraySize ((TotalCellsX -1) * (TotalCellsY-1 ))

using namespace std;



class Example : public App
{
private:
	SavingAndLoading InputOutput;
public:

	Example();
	virtual ~Example();
	virtual bool start();
	virtual void update(float deltaT);
	virtual void render();
	virtual void cleanup();
	virtual void Grid();	
	static Example &inst();
	
		
	sf::Sprite *m_backgroundSprite;

	sf::Texture* RedTile;
	sf::Texture* BlueTile;
	sf::Texture* GreenTile;
	sf::Texture* OrangeTile;
	sf::Texture* YellowTile;

	sf::RectangleShape lineHor[TotalCellsY];		
	sf::RectangleShape lineVer[TotalCellsX];

	Tile tiles[TilesArraySize];

	std::vector<sf::Sprite> sprites;


	
	bool Undo;
	bool Clear;		
	int TileId;
};
