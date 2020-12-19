#include "Options.h"
#include "SceneManager.h"


Options::Options(sf::RenderWindow& window, SceneManager& sceneManager) : m_window(window), m_sceneManager(sceneManager)
{

};

Options::~Options() {

}

bool Options::start() {

	m_backgroundSprite = kage::TextureManager::getSprite("data/retro.png");
	sf::Vector2u resolution = m_backgroundSprite->getTexture()->getSize();
	m_backgroundSprite->setScale(float(m_window.getSize().x) / resolution.x, float(m_window.getSize().y) / resolution.y);

#pragma region TextSetup

	if (!textFont.loadFromFile("./data/arcade.ttf")) {
		std::cout << "font not found" << std::endl;
	}

	for (size_t i = 0; i < Text_Array_Size; i++)
	{
		texts[i].setFont(textFont);
		texts[i].setCharacterSize(60);
		texts[i].setColor(sf::Color::Black);
	}
	texts[0].setString("Volume");
	texts[1].setString("Graphics");
	texts[2].setString("Back To Menu");

	for (size_t i = 0; i < Text_Array_Size; i++)
	{
		texts[i].setPosition(sf::Vector2f(m_window.getSize().x / 2 - texts[i].getGlobalBounds().width / 2,
			(m_window.getSize().y / 2 - 400 - texts[i].getGlobalBounds().height / 2)
			+ (i * Local_Text_Offset_Y) + Global_Text_Offset_Y));
	}
	texts[selectedItem].setColor(sf::Color::White);

#pragma endregion

	return true;
}

void Options::update(float deltaT) {

#pragma region InputSystem

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter) && isKeyReleasedPreviously && selectedItem == 2)
	{
		m_sceneManager.Run(2);
		isKeyReleasedPreviously = false;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && isKeyReleasedPreviously)
	{
		if (selectedItem < Text_Array_Size - 1) {
			selectedItem++;
		}
		else
		{
			selectedItem = 0;
		}
		for (size_t i = 0; i < Text_Array_Size; i++)
		{
			texts[i].setColor(sf::Color::Black);
		}
		texts[selectedItem].setColor(sf::Color::White);

		isKeyReleasedPreviously = false;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && isKeyReleasedPreviously)
	{
		if (selectedItem > 0) {
			selectedItem--;
		}
		else
		{
			selectedItem = Text_Array_Size - 1;
		}
		for (size_t i = 0; i < Text_Array_Size; i++)
		{
			texts[i].setColor(sf::Color::Black);
		}
		texts[selectedItem].setColor(sf::Color::White);

		isKeyReleasedPreviously = false;
	}

	if (App::isKeyReleased)
	{
		isKeyReleasedPreviously = true;
	}
	else
	{
		isKeyReleasedPreviously = false;
	}

#pragma endregion

}

void Options::render() {

	m_window.draw(*m_backgroundSprite);

	for (size_t i = 0; i < Text_Array_Size; i++)
	{
		m_window.draw(texts[i]);
	}
}
