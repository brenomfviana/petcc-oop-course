#include "menu.hpp"
#include <iostream>

Menu::Menu() : _msg("Menu"), _entity() { }

void Menu::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	// Desenhando o número de trabalhadores
	sf::Font font;
	//sf::String path = "./fonts/04b30/04B_30__.TTF";
	//sf::String path = "./fonts/fipps/Fipps-Regular.otf";
	//sf::String path = "./fonts/Terminalscope/terminalscope.ttf";
	sf::String path = "./fonts/8-bit-madness/8-Bit Madness.ttf";
	
	if (!font.loadFromFile(path))
	{
		// handle exception
	}
	if (Worker* w = dynamic_cast<Worker*>(_entity))
	{
		sf::Text text("Worker\n-Quantity: 1\n", font, 16);
		text.setPosition(400, 24);
		target.draw(text, states);
	} 
	if (Village* v = dynamic_cast<Village*>(_entity))
	{
		sf::Text text("Village\n-Build Worker\n-Build Warrior\n", font, 16);
		text.setPosition(400, 24);
		target.draw(text, states);
	}
	// Converts an int into a string
	sf::Text text(_msg, font, 16);
	text.setPosition(400, 8);
	//text.setFillColor(sf::Color::Red);

	target.draw(text, states);
}

void Menu::set_msg(sf::String msg)
{
	_msg = msg;
}

void Menu::set_msg(char* msg)
{
	_msg = msg;
}

void Menu::set_entity(Entity* entity)
{
	_entity = entity;
}

void Menu::handle_input(sf::Event event)
{

}
