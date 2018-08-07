#include "village.hpp"

Village::Village()
{
	// Empty
}

void Village::draw(sf::RenderTarget& target, 
		sf::RenderStates states) const
{
	_assets.setTextureRect(sf::IntRect(2*16, 7*16, 32 ,32));
	_assets.setPosition(get_x()*16, get_y()*16);
	target.draw(_assets, states);
}

void Village::my_draw() const
{
	_assets.setTextureRect(sf::IntRect(2*16, 7*16, 32 ,32));
	_assets.setPosition(get_x()*16, get_y()*16);
	//target.draw(_assets, states);
}