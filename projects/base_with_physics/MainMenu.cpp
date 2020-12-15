#include "MainMenu.h"

MainMenu::MainMenu(sf::RenderWindow& window) : m_window(window)
{

};

MainMenu::~MainMenu() {

}

bool MainMenu::start() {

	m_backgroundSprite = kage::TextureManager::getSprite("data/retro.png");
	sf::Vector2u resolution = m_backgroundSprite->getTexture()->getSize();
	m_backgroundSprite->setScale(float(m_window.getSize().x) / resolution.x, float(m_window.getSize().y) / resolution.y);
	buttonState1 = BTN_IDLE1;
	buttonState2 = BTN_IDLE2;
	buttonState3 = BTN_IDLE3;
	if (!textFont.loadFromFile("./data/arcade.ttf")) {
		std::cout << "font not found" << std::endl;
	}

	for (size_t i = 0; i < Text_Array_Size; i++)
	{
		texts[i].setFont(textFont);
		texts[i].setCharacterSize(60);
	}
	texts[0].setString("Start");
	buttonShape[0].setSize(sf::Vector2f(290, 70));
	texts[1].setString("Options");
	buttonShape[1].setSize(sf::Vector2f(410, 70));
	texts[2].setString("Exit");
	buttonShape[2].setSize(sf::Vector2f(230, 70));


	for (size_t i = 0; i < Text_Array_Size; i++)
	{
		texts[i].setPosition(sf::Vector2f(m_window.getSize().x / 2 - texts[i].getGlobalBounds().width / 2,
										 (m_window.getSize().y / 2 -400 - texts[i].getGlobalBounds().height / 2)
										  + (i * Local_Text_Offset_Y) + Global_Text_Offset_Y));
		buttonShape[i].setPosition(sf::Vector2f(m_window.getSize().x / 2 - texts[i].getGlobalBounds().width / 2,
												(m_window.getSize().y / 2 - 400 - texts[i].getGlobalBounds().height / 2)
												+ (i * Local_Text_Offset_Y) + Global_Text_Offset_Y));
	}
	return true;
}


void MainMenu::update(float deltaT)
{

	buttonState1 = BTN_IDLE1;
	buttonState2 = BTN_IDLE2;
	buttonState3 = BTN_IDLE3;//Idle	
	sf::Vector2i mousePosition = sf::Mouse::getPosition(m_window);
	sf::Vector2f newMousePos = sf::Vector2f(mousePosition);

	if (buttonShape[0].getGlobalBounds().contains(newMousePos)) { //Hovered on Button

		buttonState1 = BTN_HOVER1;

		if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) { //Clicked Button

			buttonState1 = BTN_PRESSED1;
		}
	}
	switch (buttonState1)
	{
	case BTN_IDLE1:
		buttonShape[0].setFillColor(sf::Color(70, 70, 70, 200));
		break;
	case BTN_HOVER1:
		buttonShape[0].setFillColor(sf::Color(150, 150, 150, 255));
		break;
	case BTN_PRESSED1:
		buttonShape[0].setFillColor(sf::Color(20, 20, 20, 200));
		break;
	}

	if (buttonShape[1].getGlobalBounds().contains(newMousePos)) { //Hovered on Button

		buttonState2 = BTN_HOVER2;

		if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) { //Clicked Button

			buttonState2= BTN_PRESSED2;
		}
	}
	switch (buttonState2)
	{
	case BTN_IDLE2:
		buttonShape[1].setFillColor(sf::Color(70, 70, 70, 200));
		break;
	case BTN_HOVER2:
		buttonShape[1].setFillColor(sf::Color(150, 150, 150, 255));
		
		break;
	case BTN_PRESSED2:
		buttonShape[1].setFillColor(sf::Color(20, 20, 20, 200));
		break;
	}

	if (buttonShape[2].getGlobalBounds().contains(newMousePos)) { //Hovered on Button

		buttonState3 = BTN_HOVER3;

		if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) { //Clicked Button

			buttonState3 = BTN_PRESSED3;
			
		}
	}
	switch (buttonState3)
	{
	case BTN_IDLE3:
		buttonShape[2].setFillColor(sf::Color(70, 70, 70, 200));
		break;
	case BTN_HOVER3:
		buttonShape[2].setFillColor(sf::Color(150, 150, 150, 255));
		break;
	case BTN_PRESSED3:
		buttonShape[2].setFillColor(sf::Color(20, 20, 20, 200));
		
		break;
	}
}

		

void MainMenu::render() {
	m_window.draw(*m_backgroundSprite);
	
	for (size_t i = 0; i < Text_Array_Size; i++)
	{
		m_window.draw(buttonShape[i]);
	}
	for (size_t i = 0; i < Text_Array_Size; i++)
	{
		m_window.draw(texts[i]);
	}
	
	
}

void MainMenu::cleanup() {
	delete m_backgroundSprite;
}