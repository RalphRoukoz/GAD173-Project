#pragma once

#include "app.h"
#include"kage2dutil/physics.h"

#define Text_Array_Size 3
#define Local_Text_Offset_Y 200
#define Global_Text_Offset_Y 200

class SceneManager;

class Options
{
private:
	SceneManager& m_sceneManager;
	sf::RenderWindow& m_window;
	sf::Sprite* m_backgroundSprite;
	sf::Font textFont;
	sf::Text texts[Text_Array_Size];
public:
	Options(sf::RenderWindow& window,SceneManager& sceneManager);
	~Options();
	bool start();
	void update(float deltaT);
	void render();
	void cleanup();

	int selectedItem = 0;

	bool isKeyReleasedPreviously;
};

