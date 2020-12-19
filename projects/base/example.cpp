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
#pragma region LoadingSpritesAndFonts

	m_backgroundSprite = kage::TextureManager::getSprite("data/retro.jpg");

	if (!textFont.loadFromFile("./data/arcade.ttf")) {
		std::cout << "font not found" << std::endl;
	}

	RedTile = kage::TextureManager::getTexture("data/RedTile.png");
	BlueTile = kage::TextureManager::getTexture("data/BlueTile.png");
	GreenTile = kage::TextureManager::getTexture("data/GreenTile.png");
	YellowTile = kage::TextureManager::getTexture("data/YellowTile.png");
	OrangeTile = kage::TextureManager::getTexture("data/OrangeTile.png");

	sf::Vector2u resolution = m_backgroundSprite->getTexture()->getSize();
	m_backgroundSprite->setScale(float(m_window.getSize().x) / resolution.x, float(m_window.getSize().y) / resolution.y);

#pragma endregion

#pragma region SettingUpTexts

	
	text.setFont(textFont);
	text.setCharacterSize(30);
	text.setColor(sf::Color::White);	
	text.setString(ActiveTile);
	text.setPosition(sf::Vector2f(m_window.getSize().x / 2  - text.getGlobalBounds().width / 2,
		(m_window.getSize().y / 2 -500 - text.getGlobalBounds().height / 2) +1));
#pragma endregion

	Grid();

	return true;
}

void Example::update(float deltaT)
{	
#pragma region CheckingMousePositionToAddTilesOnGrid

	sf::Vector2i mousePosition = sf::Mouse::getPosition(m_window);
	float indexX;
	float indexY;
	int newindexX;
	int newindexY;

	indexX = mousePosition.x / 270;
	newindexX = (int)indexX;

	indexY =  mousePosition.y / 90;
	newindexY = (int)indexY;

	sf::Sprite Tilesprites;

#pragma endregion

#pragma region InputButtons

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num1) && isKeyReleasedPreviously)
	{
		TileId = 1;
		ActiveTile = "RedTile is Active";
		text.setString(ActiveTile);
		isKeyReleasedPreviously = false;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num2) && isKeyReleasedPreviously)
	{
		TileId = 2;
		ActiveTile = "Blue is Active";
		text.setString(ActiveTile);
		isKeyReleasedPreviously = false;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num3) && isKeyReleasedPreviously)
	{
		TileId = 3;
		ActiveTile = "Green is Active";
		text.setString(ActiveTile);
		isKeyReleasedPreviously = false;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num4) && isKeyReleasedPreviously)
	{
		TileId = 4;
		ActiveTile = "Orange is Active";
		text.setString(ActiveTile);
		isKeyReleasedPreviously = false;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num5) && isKeyReleasedPreviously)
	{
		TileId = 5;
		ActiveTile = "Yellow is Active";
		text.setString(ActiveTile);
		isKeyReleasedPreviously = false;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) && sf::Keyboard::isKeyPressed(sf::Keyboard::LControl))
	{
		InputOutput.Save(tiles, TotalCellsY, (TotalCellsY));
		ActiveTile = "Map Saved";
		text.setString(ActiveTile);
		isKeyReleasedPreviously = false;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::L) && sf::Keyboard::isKeyPressed(sf::Keyboard::LControl) && isKeyReleasedPreviously)
	{
		InputOutput.Load();
		ActiveTile = "Map Loaded";
		text.setString(ActiveTile);
		isKeyReleasedPreviously = false;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Delete) )
	{
		ActiveTile = "Cleared Tiles";
		text.setString(ActiveTile);
		Clear = true;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape) && m_window.hasFocus())
	{
		m_running = false;
	}

	if (App::isKeyReleased)
	{
		isKeyReleasedPreviously = true;
	}
	else
	{
		isKeyReleasedPreviously = false;
	}
	if (Clear == true)
	{
		sprites.clear();
		Clear = false;
	}

#pragma endregion
		
#pragma region SwitchingCasesForTileColors

	switch (TileId)
	{
	case 0:
		break;
	case 1:
		Tilesprites.setTexture(*RedTile);
		break;
	case 2:
		Tilesprites.setTexture(*BlueTile);
		break;
	case 3:
		Tilesprites.setTexture(*GreenTile);
		break;
	case 4:
		Tilesprites.setTexture(*OrangeTile);
		break;
	case 5:
		Tilesprites.setTexture(*YellowTile);
		break;
	default:
		break;
	}

#pragma endregion
	
#pragma region PrintingTilesOnceClickingWithMouse

	if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {

		if (newindexX >= 0 && newindexY >= 1 && newindexX < (TotalCellsX - 1) && newindexY  < (TotalCellsY))
		{
			Tilesprites.setPosition(sf::Vector2f(newindexX * CellWidth, newindexY * CellHeight));
			sprites.push_back(Tilesprites);
			render();

			int i = newindexX + newindexY * (TotalCellsX - 1);
			tiles[i].id = TileId;
		}
	}
#pragma endregion
			
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
	for (size_t i = 0; i < Text_Array_Size; i++)
	{
		m_window.draw(text);
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

