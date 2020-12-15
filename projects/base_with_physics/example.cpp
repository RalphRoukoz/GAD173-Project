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

	ImGui::Begin("Kage2D");
	if(ImGui::Button("Start Game"))
	{ 
		sceneManager.Run(2);
	}
	if (ImGui::Button("Option"))
	{
		sceneManager.Run(1);
	}
	if (ImGui::Button("Back To Menu"))
	{
		sceneManager.Run(0);
	}
	if (ImGui::Button("Exit"))
	{
		m_running = false;
	}
	ImGui::End();

	sceneManager.Update(deltaT);
}

void Example::render()
{
	sceneManager.Render();
}

void Example::cleanup()
{

}

