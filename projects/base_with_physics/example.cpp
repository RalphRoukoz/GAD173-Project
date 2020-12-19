#include "example.h"

Example::Example(): App(), sceneManager(m_window)
{
}

Example::~Example()
{
}

bool Example::start()
{
	
	sceneManager.Start();
	return true;
}

void Example::update(float deltaT)
{

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape) && m_window.hasFocus())
	{
		m_running = false;
	}


	sceneManager.Update(deltaT);
}

void Example::render()
{
	sceneManager.Render();
}

void Example::cleanup()
{

}

