#pragma once

#include "app.h"
#include"kage2dutil/physics.h"
#include "Tile.h"
#include <fstream>
class StartGame
{
private:
	sf::RenderWindow& m_window;
	sf::Sprite* m_backgroundSprite;
	sf::RectangleShape Padel;
	sf::Music backgroundMusic;

	sf::Texture* RedTile;
	sf::Texture* BlueTile;
	sf::Texture* GreenTile;
	sf::Texture* OrangeTile;
	sf::Texture* YellowTile;

	std::vector<sf::Sprite> sprites; 

	Tile tiles[70];

	bool isKeyReleasedPreviously;
	int movementSpeed = 4;

public:
	StartGame(sf::RenderWindow& window);
	~StartGame();
	bool start();
	void update(float deltaT);
	void render();
	void cleanup();
	
};

