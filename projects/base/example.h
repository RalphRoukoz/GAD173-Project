#pragma once

#include "app.h"
#include <vector>
#include <fstream>
#include <iostream>
#include <string>
#include "Tile.h"
#include "SavingAndLoading.h"

#define Text_Array_Size 9

#define Local_Text_Offset_Y 100
#define Global_Text_Offset_Y 100

#define LineThickness 2

#define CellHeight 90
#define CellWidth 270

#define GridOffSetX 0 
#define GridOffSetY 90

#define TotalCellsX 7+ 1
#define TotalCellsY 9 + 1

#define TilesArraySize ((TotalCellsX -1) * (TotalCellsY-1 ))

using namespace std;

class Example : public App
{
private:
	SavingAndLoading InputOutput;

	sf::Sprite* m_backgroundSprite;
	sf::Sprite Tilesprites;

	sf::Texture* RedTile;
	sf::Texture* BlueTile;
	sf::Texture* GreenTile;
	sf::Texture* OrangeTile;
	sf::Texture* YellowTile;

	sf::RectangleShape lineHor[TotalCellsY];
	sf::RectangleShape lineVer[TotalCellsX];

	sf::Font textFont;
	sf::Text text;

	std::vector<sf::Sprite> sprites;

	Tile tiles[TilesArraySize];

	bool isKeyReleasedPreviously;
	bool Clear;

	string ActiveTile = "No Tile Selected";

	int TileId;
public:

	Example();
	virtual ~Example();
	virtual bool start();
	virtual void update(float deltaT);
	virtual void render();
	virtual void cleanup();

	virtual void Grid();	
	static Example &inst();
		
};
