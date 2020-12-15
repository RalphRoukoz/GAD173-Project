#include "StartGame.h"

StartGame::StartGame(sf::RenderWindow& window): m_window(window)
{

};

StartGame::~StartGame() {

}

bool StartGame::start() {

	demon = kage::TextureManager::getSprite("data/demon.png");
	return true;
}

void StartGame::update(float deltaT) {


}

void StartGame::render() {
	m_window.draw(*demon);
}

void StartGame::cleanup() {

}