#include "SceneManager.h"

SceneManager::SceneManager(sf::RenderWindow& window) : options(window),
							game(window), menu(window)
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
		menu.update(deltaTime);
		break;
	case 1:
		options.update(deltaTime);
		break;
	case 2:
		game.update(deltaTime);
		break;
	default:
		break;
	}
}
void SceneManager::Render() {

	switch (m_index)
	{

	case 0:
		menu.render();
		break;
	case 1:
		options.render();
		break;
	case 2:
		game.render();
		break;
	default:
		break;
	}
}
