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
	static const char* Tiles[]{ "Red Tile","Blue Tile","GreenTile","OrangeTile","YellowTile" };
	static int selectedTile = 0;

	indexX = mousePosition.x / 270;
	newindexX = (int)indexX;

	indexY = mousePosition.y / 90;
	newindexY = (int)indexY;

	sf::Sprite Tilesprites;
	ImGui::Begin("Game Editor");

	ImGui::ListBox("Choose Tile", &selectedTile, Tiles, IM_ARRAYSIZE(Tiles));

	if (selectedTile == 0)
	{
		TileId = 1;
	}
	if (selectedTile == 1)
	{
		TileId = 2;
	}
	if (selectedTile == 2)
	{
		TileId = 3;
	}
	if (selectedTile == 3)
	{
		TileId = 4;
	}
	if (selectedTile == 4)
	{
		TileId = 5;
	}

	if (ImGui::Button("Clear Tiles"))
	{
		Clear = true;
	}
	if (ImGui::Button("Save"))
	{
		InputOutput.Save(tiles, TilesArraySize );
	}
	if (ImGui::Button("Load"))
	{
		InputOutput.Load();
	}
	if (ImGui::Button("Exit"))
	{
		m_running = false;
	}

	ImGui::End();

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

	if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {

		if (newindexX >= 0 && newindexY >= 0 && newindexX < (TotalCellsX - 1) && newindexY < (TotalCellsY - 1))
		{
			Tilesprites.setPosition(sf::Vector2f(newindexX * CellWidth, newindexY * CellHeight));
			sprites.push_back(Tilesprites);
			render();

			int i = newindexX + newindexY * (TotalCellsX - 1);
			tiles[i].id = TileId;
		}
	}
			
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape) && m_window.hasFocus())
	{
		m_running = false;
	}

	if (Clear == true)
	{
		sprites.clear();
		Clear = false;
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

