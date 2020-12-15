#include "Options.h"

Options::Options(sf::RenderWindow& window) : m_window(window)
{

};

Options::~Options() {

}

bool Options::start() {

	
	ship2= kage::TextureManager::getSprite("data/ship2.png");
	return true;
}

void Options::update(float deltaT) {


}

void Options::render() {
	m_window.draw(*ship2);
}

void Options::cleanup() {

}