#pragma once

#include "app.h"
#include"kage2dutil/physics.h"
class Options
{
private:
	sf::RenderWindow& m_window;
	sf::Sprite* ship2;
public:
	Options(sf::RenderWindow& window);
	~Options();
	bool start();
	void update(float deltaT);
	void render();
	void cleanup();

};

