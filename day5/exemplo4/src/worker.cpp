#include <iostream>
#include <sstream>
#include "worker.hpp"

Worker::Worker() : _color(WHITE) {}

Worker::Worker(Color color) : _color(color) {}

Worker::Worker(Color color, int x, int y) : _color(color) {
	this->set_x(x);
	this->set_y(y);
}

void Worker::draw(sf::RenderTarget& target, 
		sf::RenderStates states) const
{
	_draw_avatar();
	_assets.setPosition(Entity::_x*16, Entity::_y*16);
	target.draw(_assets, states);
	
	// Desenhando o número de trabalhadores
	sf::Font font;
	sf::String path = "./fonts/8-bit-madness/8-Bit Madness.ttf";
	
	if (!font.loadFromFile(path))
		std::cout << "Sem fonte\n";

	// Converts an int into a string
	std::stringstream strs;
	strs << get_quantity();
	sf::Text text(strs.str(), font, 16);
	text.setPosition(Entity::_x*16, Entity::_y*16);

	target.draw(text, states);
}
/**
 * 
 */	
void Worker::_draw_avatar() const 
{
	// Seleciona o tile correspondente a cor do worker
	switch ( _color )
	{
		case BLUE:
		{
			_assets.setTextureRect(sf::IntRect(2*16, 35*16, 16 ,16));
			break;
		}
		case RED:
		{
			_assets.setTextureRect(sf::IntRect(2*16, 36*16, 16 ,16));
			break;
		}
		case YELLOW:
		{
			_assets.setTextureRect(sf::IntRect(2*16, 37*16, 16 ,16));
			break;
		}
		case GREEN:
		{
			_assets.setTextureRect(sf::IntRect(4*16, 37*16, 16 ,16));
			break;
		}
		default:
			_assets.setTextureRect(sf::IntRect(5*16, 36*16, 16 ,16));
			break;
	}
}
