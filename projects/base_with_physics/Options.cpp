#include "Options.h"

Options::Options(sf::RenderWindow& window) : m_window(window)
{

};

Options::~Options() {

}

bool Options::start() {

	
	m_backgroundSprite = kage::TextureManager::getSprite("data/retro.png");
	sf::Vector2u resolution = m_backgroundSprite->getTexture()->getSize();
	m_backgroundSprite->setScale(float(m_window.getSize().x) / resolution.x, float(m_window.getSize().y) / resolution.y);
	return true;
}

void Options::update(float deltaT) {


}

void Options::render() {
	m_window.draw(*m_backgroundSprite);
}

void Options::cleanup() {

}