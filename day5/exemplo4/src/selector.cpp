#include "selector.hpp"

Selector::Selector()
{
	// Empty
}

void Selector::draw(sf::RenderTarget& target, 
		sf::RenderStates states) const
{
	if (_selected)
		_assets.setTextureRect(sf::IntRect(3*16, 42*16, 16 ,16));
	else 
		_assets.setTextureRect(sf::IntRect(4*16, 42*16, 16 ,16));
	_assets.setPosition(get_x()*16, get_y()*16);
	target.draw(_assets, states);
}

void Selector::handle_input(sf::Event event)
{
	switch (event.type)
	{
		case sf::Event::KeyPressed:
		{
			switch(event.key.code)
			{
				case sf::Keyboard::Right:
					set_x(get_x() + 1);
					set_selected(false);
					break;
				case sf::Keyboard::Down:
					set_y(get_y() + 1);
					set_selected(false);
					break;
				case sf::Keyboard::Left:
					set_x(get_x() - 1);
					set_selected(false);
					break;
				case sf::Keyboard::Up:
					set_y(get_y() - 1);
					set_selected(false);
					break;
				case sf::Keyboard::Enter:
					Entity::_selected = Entity::_selected ? false : true;
					break;
				default:
					break;
			}
		} break;
		default:
			break;
	}
}
