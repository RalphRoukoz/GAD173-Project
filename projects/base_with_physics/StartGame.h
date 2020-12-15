#pragma once

#include "app.h"
#include"kage2dutil/physics.h"
class StartGame
{
private:
	sf::RenderWindow& m_window;
	sf::Sprite* demon;
public:
	StartGame(sf::RenderWindow& window);
	~StartGame();
	bool start();
	void update(float deltaT);
	void render();
	void cleanup();
	
};

