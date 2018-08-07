#include "entity.hpp"

// Inicialização dos atributos static. Não é possível inicializar no header
sf::Texture Entity::_texture;
sf::Sprite Entity::_assets;

Entity::Entity(int x, int y) : _x(x), _y(y), _selected(false)
{
	_texture.loadFromFile("TMSSPack/Tile-set - Toen's Medieval Strategy (16x16) - v.1.0.png");
	_assets.setTexture(_texture);
}

void Entity::set_x(int x)
{
	if (x > MAP_WIDTH-1 or x < 0)
	{
		return;
	}
	_x = x;
}

void Entity::set_y(int y)
{
	if (y > MAP_HEIGHT-1 or y < 0)
	{
		return;
	}
	_y = y;
}

int Entity::get_x() const
{
	return _x;
}

int Entity::get_y() const
{
	return _y;
}

bool Entity::is_selected() const
{
	return _selected;
}

void Entity::set_selected(bool selected)
{
	_selected = selected;
}
