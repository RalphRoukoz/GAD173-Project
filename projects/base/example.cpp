#include "example.h"

Example::Example(): App()
{
}

Example::~Example()
{
}

Example &Example::inst()
{
	static Example s_instance;
	return s_instance;
}

bool Example::start()
{
	RedisActive = false;
	GreenisActive = false;
	BlueisActive = false;

	m_backgroundSprite = kage::TextureManager::getSprite("data/sky.jpg");

	RedTile = kage::TextureManager::getTexture("data/RedTile.png");
	BlueTile = kage::TextureManager::getTexture("data/BlueTile.png");
	GreenTile = kage::TextureManager::getTexture("data/GreenTile.png");



	sf::Vector2u resolution = m_backgroundSprite->getTexture()->getSize();
	m_backgroundSprite->setScale(float(m_window.getSize().x) / resolution.x, float(m_window.getSize().y) / resolution.y);
	
	for (int i = 0; i < TotalCellsX ; i++)
	{			
		lineVer[i] = sf::RectangleShape(sf::Vector2f(LineThickness, CellHeight * TotalCellsY)); //Size of the cell
		lineVer[i].setFillColor(sf::Color::White);
		lineVer[i].setPosition(sf::Vector2f(GridOffSetX + CellWidth * i, GridOffSetY));					//Position of the cell
	}

	for (int i = 0; i < TotalCellsY ; i++)
	{					
		lineHor[i] = sf::RectangleShape(sf::Vector2f(CellWidth * TotalCellsX, LineThickness));
		lineHor[i].setFillColor(sf::Color::White);
		lineHor[i].setPosition(sf::Vector2f(GridOffSetX, CellHeight * i + GridOffSetY));		
	}
	
	return true;
}

void Example::update(float deltaT)
{	
	sf::Vector2i mousePosition = sf::Mouse::getPosition(m_window);	
	float indexX;
	float indexY;
	int newindexX;
	int newindexY;
	int w = 6;

	indexX = mousePosition.x / 270;
	newindexX = (int)indexX;

	indexY = mousePosition.y / 90;
	newindexY = (int)indexY;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape) && m_window.hasFocus())
	{
		m_running = false;
	}
	
	if (RedisActive == true && sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
			
		if (newindexX >= 0 && newindexY >= 0 && newindexX < (TotalCellsX - 1) && newindexY < (TotalCellsY - 1))
		{
			sf::Sprite Red;
			Red.setTexture(*RedTile);
			Red.setPosition(sf::Vector2f(newindexX * CellWidth, newindexY * CellHeight));
			sprites.push_back(Red);
			render();

		}
	}
	if (GreenisActive == true && sf::Mouse::isButtonPressed(sf::Mouse::Left)) {		

		if (newindexX >= 0 && newindexY >= 0 && newindexX < (TotalCellsX - 1) && newindexY < (TotalCellsY - 1))
		{
			sf::Sprite Green;
			Green.setTexture(*GreenTile);
			Green.setPosition(sf::Vector2f(newindexX * CellWidth, newindexY * CellHeight));
			sprites.push_back(Green);
			render();
		}
	}
	if (BlueisActive == true && sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
		if (newindexX >= 0 && newindexY >= 0 && newindexX < (TotalCellsX - 1) && newindexY < (TotalCellsY - 1))
		{
			sf::Sprite Blue;
			Blue.setTexture(*BlueTile);
			Blue.setPosition(sf::Vector2f(newindexX * CellWidth, newindexY * CellHeight));
			sprites.push_back(Blue);
			render();
		}
	}

	ImGui::Begin("Game Editor");
	if(ImGui::Button("Exit"))
	{ 
		m_running = false;
	}
	if (ImGui::Button ("RedTile"))
	{
		RedisActive = true;
		GreenisActive = false;
		BlueisActive = false;
		
	}
	if (ImGui::Button("GreenTile"))
	{
	
		RedisActive = false;
		GreenisActive = true;
		BlueisActive = false;
	}
	if (ImGui::Button("BlueTile"))
	{
		
		RedisActive = false;
		GreenisActive = false;
		BlueisActive = true;
	}
	if (ImGui::Button("Exit"))
	{
		m_running = false;
	}
	if (ImGui::Button("Save"))
	{
		m_running = false;
	}
	if (ImGui::Button("Load"))
	{
		m_running = false;
	}
	ImGui::End();
}

void Example::render()
{
	m_window.draw(*m_backgroundSprite);
	
	for (size_t i = 0; i < TotalCellsX; i++)
	{
		m_window.draw(lineVer[i]);
	}
	for (size_t i = 0; i < TotalCellsY; i++)
	{
		m_window.draw(lineHor[i]);
	}
	for (size_t i = 0; i < sprites.size(); i++)
	{			
		m_window.draw(sprites[i]);
					
	}

}

void Example::cleanup()
{
	delete m_backgroundSprite;
}

