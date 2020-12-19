#include "StartGame.h"

StartGame::StartGame(sf::RenderWindow& window): m_window(window)
{

};

StartGame::~StartGame() {

}

bool StartGame::start() {

	m_backgroundSprite = kage::TextureManager::getSprite("data/Game.jpg");
	sf::Vector2u resolution = m_backgroundSprite->getTexture()->getSize();
	m_backgroundSprite->setScale(float(m_window.getSize().x) / resolution.x, float(m_window.getSize().y) / resolution.y);

#pragma region PadelSetup

	Padel.setPosition(sf::Vector2f(m_window.getSize().x / 2 - Padel.getGlobalBounds().width / 2 - 100, 1000));
	Padel.setSize(sf::Vector2f(200, 20));
	Padel.setFillColor(sf::Color::White);

#pragma endregion


	return true;
}

void StartGame::update(float deltaT) {
#pragma region InputSystem

	sf::Vector2f position = Padel.getPosition();

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		if (position.x <= 1800)
		{
			Padel.move(movementSpeed * 20 / 2, 0);
		}
		isKeyReleasedPreviously = false;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		if (position.x >= 100)
		{
			Padel.move(-movementSpeed * 20 / 2, 0);
		}
		isKeyReleasedPreviously = false;
	}

#pragma endregion

}

void StartGame::render() {
	m_window.draw(*m_backgroundSprite);
	m_window.draw(Padel);
}

void StartGame::cleanup() {

}