#include "SceneManager.h"

SceneManager::SceneManager(sf::RenderWindow& window) : menu(window, *this), options(window,* this),
							game(window)
{ 

};

SceneManager::~SceneManager() {

}

void SceneManager::Run(int index) {


	m_index = index;	
}

void SceneManager::Start() {
	options.start();
	game.start();
	menu.start();
}

void SceneManager::Update(float deltaTime) {

	switch (m_index)
	{
	case 0:
		game.update(deltaTime);
		break;
	case 1:
		options.update(deltaTime);
		break;
	case 2:
		menu.update(deltaTime);
		break;
	default:
		break;
	}
}
void SceneManager::Render() {

	switch (m_index)
	{
	case 0:
		game.render();
		break;
	case 1:
		options.render();
		break;
	case 2:
		menu.render();
		break;
	default:
		break;
	}
}
