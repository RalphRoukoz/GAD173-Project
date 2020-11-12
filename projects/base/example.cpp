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
	YellowisActive = false;
	OrangeisActive = false;

	m_backgroundSprite = kage::TextureManager::getSprite("data/sky.jpg");

	RedTile = kage::TextureManager::getTexture("data/RedTile.png");
	BlueTile = kage::TextureManager::getTexture("data/BlueTile.png");
	GreenTile = kage::TextureManager::getTexture("data/GreenTile.png");
	YellowTile = kage::TextureManager::getTexture("data/YellowTile.png");
	OrangeTile = kage::TextureManager::getTexture("data/OrangeTile.png");

	sf::Vector2u resolution = m_backgroundSprite->getTexture()->getSize();
	m_backgroundSprite->setScale(float(m_window.getSize().x) / resolution.x, float(m_window.getSize().y) / resolution.y);
	
	Grid();
	
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
	static const char* Tiles[]{ "Red Tile","Blue Tile","GreenTile","OrangeTile","YellowTile" };
	static int selectedTile = 0;

	indexX = mousePosition.x / 270;
	newindexX = (int)indexX;

	indexY = mousePosition.y / 90;
	newindexY = (int)indexY;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape) && m_window.hasFocus())
	{
		m_running = false;

	}

	ImGui::Begin("Game Editor");

	ImGui::ListBox("Choose Tile", &selectedTile, Tiles, IM_ARRAYSIZE(Tiles));

	if (selectedTile == 0)
	{
		RedisActive = true;
		GreenisActive = false;
		BlueisActive = false;
		OrangeisActive = false;
		YellowisActive = false;

	}
	if (selectedTile == 1)
	{
		RedisActive = false;
		GreenisActive = false;
		BlueisActive = true;
		OrangeisActive = false;
		YellowisActive = false;
	}
	if (selectedTile == 2)
	{
		RedisActive = false;
		GreenisActive = true;
		BlueisActive = false;
		OrangeisActive = false;
		YellowisActive = false;
	}
	if (selectedTile == 3)
	{
		RedisActive = false;
		GreenisActive = false;
		BlueisActive = false;
		OrangeisActive = true;
		YellowisActive = false;
	}
	if (selectedTile == 4)
	{
		RedisActive = false;
		GreenisActive = false;
		BlueisActive = false;
		OrangeisActive = false;
		YellowisActive = true;
	}


	if (ImGui::Button("Clear Tiles"))
	{
		Clear = true;
	}
	if (ImGui::Button("Exit"))
	{
		m_running = false;
	}

	ImGui::End();
	if (Clear == true)
	{	
		
		sprites.clear();
		Clear = false;
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
	if (YellowisActive == true && sf::Mouse::isButtonPressed(sf::Mouse::Left)) {

		if (newindexX >= 0 && newindexY >= 0 && newindexX < (TotalCellsX - 1) && newindexY < (TotalCellsY - 1))
		{
			sf::Sprite Yellow;
			Yellow.setTexture(*YellowTile);
			Yellow.setPosition(sf::Vector2f(newindexX * CellWidth, newindexY * CellHeight));
			sprites.push_back(Yellow);
			render();
		}

	}
	if (OrangeisActive == true && sf::Mouse::isButtonPressed(sf::Mouse::Left)) {

		if (newindexX >= 0 && newindexY >= 0 && newindexX < (TotalCellsX - 1) && newindexY < (TotalCellsY - 1))
		{
			sf::Sprite Orange;
			Orange.setTexture(*OrangeTile);
			Orange.setPosition(sf::Vector2f(newindexX * CellWidth, newindexY * CellHeight));
			sprites.push_back(Orange);
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

void Example::Grid() {

	for (int i = 0; i < TotalCellsX; i++)
	{
		lineVer[i] = sf::RectangleShape(sf::Vector2f(LineThickness, CellHeight * TotalCellsY)); //Size of the cell
		lineVer[i].setFillColor(sf::Color::White);
		lineVer[i].setPosition(sf::Vector2f(GridOffSetX + CellWidth * i, GridOffSetY));					//Position of the cell
	}

	for (int i = 0; i < TotalCellsY; i++)
	{
		lineHor[i] = sf::RectangleShape(sf::Vector2f(CellWidth * TotalCellsX, LineThickness));
		lineHor[i].setFillColor(sf::Color::White);
		lineHor[i].setPosition(sf::Vector2f(GridOffSetX, CellHeight * i + GridOffSetY));
	}
}

void Example::cleanup()
{
	delete m_backgroundSprite;
}

