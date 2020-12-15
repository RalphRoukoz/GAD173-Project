#pragma once
#pragma once

#include "app.h"
#include"kage2dutil/physics.h"


#define Text_Array_Size 3
#define Local_Text_Offset_Y 200
#define Global_Text_Offset_Y 200

enum button_States1{BTN_IDLE1 = 0, BTN_HOVER1, BTN_PRESSED1};
enum button_States2 { BTN_IDLE2 = 0, BTN_HOVER2, BTN_PRESSED2 };
enum button_States3 { BTN_IDLE3 = 0, BTN_HOVER3, BTN_PRESSED3 };
class MainMenu: public App
{
private:
	short unsigned buttonState1;
	short unsigned buttonState2;
	short unsigned buttonState3;
	bool clicked;
	bool hover;
	sf::RenderWindow& m_window;
	sf::Font textFont;
	sf::Text texts[Text_Array_Size];
	sf::Sprite* m_backgroundSprite;
	sf::RectangleShape buttonShape[Text_Array_Size];
	
	
	
public:
	MainMenu(sf::RenderWindow& window);
	~MainMenu();
	bool start();
	void update(float deltaT);
	void render();	
	void cleanup();

};

