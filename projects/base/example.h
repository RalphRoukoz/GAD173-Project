#pragma once

#include "app.h"

#define LineThickness 2

#define CellHeight 30
#define CellWidth 196

#define GridOffSetX 0 
#define GridOffSetY 0

#define TotalCellsX 6 + 1
#define TotalCellsY 33 + 1



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

	sf::RectangleShape lineHor[TotalCellsY];	
	
	sf::RectangleShape lineVer[TotalCellsX];	

};
