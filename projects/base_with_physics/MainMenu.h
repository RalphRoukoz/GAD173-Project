#pragma once
#pragma once

#include "app.h"
#include"kage2dutil/physics.h"


#define Text_Array_Size 3
#define Local_Text_Offset_Y 200
#define Global_Text_Offset_Y 200

class SceneManager;

class MainMenu: public App
{
private:

	sf::RenderWindow& m_window;
	SceneManager& m_sceneManager;
	sf::Font textFont;
	sf::Text texts[Text_Array_Size];
	sf::Sprite* m_backgroundSprite;
	sf::Music backgroundMusic;

public:

	MainMenu(sf::RenderWindow& window, SceneManager& sceneManager);
	~MainMenu();
	bool start();
	void update(float deltaT);
	void render();	
	void cleanup();

	int selectedItem = 0;

	bool isKeyReleasedPreviously;
};

