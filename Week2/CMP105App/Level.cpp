#include "Level.h"
#include <string.h>

Level::Level(sf::RenderWindow* hwnd, Input* in)
{
	window = hwnd;
	input = in;

	// initialise game objects

	if (!font.loadFromFile("font/arial.ttf")) {

		std::cout << "Error loading font\n";

	}

	text.setFont(font);
	
	text.setCharacterSize(24);
	text.setPosition(0, 0);

}

Level::~Level()
{
	input = nullptr;
}

// handle user input
void Level::handleInput()
{
	if (input->isKeyDown(sf::Keyboard::W)) {

		input->setKeyUp(sf::Keyboard::W);
		std::cout << "W Pressed";

	}

	if (input->isKeyDown(sf::Keyboard::J) && input->isKeyDown(sf::Keyboard::K) && input->isKeyDown(sf::Keyboard::L)) {

		std::cout << "J, K and L pressed";

	}

	if (input->isKeyDown(sf::Keyboard::Escape)) {
		
		window->close();

	}

}

// Update game objects
void Level::update()
{
	mouseString = "Current Position: ";
	mouseString += std::to_string(input->getMouseX());
	mouseString += ", ";
	mouseString += std::to_string(input->getMouseY());

	text.setString(mouseString);

	
}

// Render level
void Level::render()
{
	beginDraw();

	window->draw(text);

	endDraw();
}

// Begins rendering to the back buffer. Background colour set to light blue.
void Level::beginDraw()
{
	window->clear(sf::Color(100, 149, 237));
}

// Ends rendering to the back buffer, and swaps buffer to the screen.
void Level::endDraw()
{
	window->display();
}