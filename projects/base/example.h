#pragma once

#include "app.h"
#include <vector>
#include <fstream>
#include <iostream>
#include <string>

#define LineThickness 2

#define CellHeight 90
#define CellWidth 270

#define GridOffSetX 0 
#define GridOffSetY 0

#define TotalCellsX 6+ 1
#define TotalCellsY 10 + 1



class Example : public App
{
public:

	Example();
	virtual ~Example();
	virtual bool start();
	virtual void update(float deltaT);
	virtual void render();
	virtual void cleanup();
	static Example &inst();
		
	sf::Sprite *m_backgroundSprite;
	

	sf::Texture* RedTile;
	sf::Texture* BlueTile;
	sf::Texture* GreenTile;
	sf::Texture* OrangeTile;
	sf::Texture* YellowTile;


	sf::RectangleShape lineHor[TotalCellsY];		
	sf::RectangleShape lineVer[TotalCellsX];	

	std::vector<sf::Sprite> sprites;
	

	bool RedisActive;
	bool GreenisActive;
	bool BlueisActive;
	bool YellowisActive;
	bool OrangeisActive;
	bool Undo;
	bool Clear;
	
};
