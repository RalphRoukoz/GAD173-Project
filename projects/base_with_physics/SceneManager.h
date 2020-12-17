#pragma once

#include "Options.h"
#include"StartGame.h"
#include"MainMenu.h"
class SceneManager
{
private:
	Options options;
	StartGame game;
	MainMenu menu;
	int m_index = 2;
public:
	SceneManager(sf::RenderWindow& window);
	~SceneManager();
	void Run(int index);
	void Start();
	void Update(float deltaTime);
	void Render();
};

