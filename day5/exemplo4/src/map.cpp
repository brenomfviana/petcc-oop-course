#include "map.hpp"

Map::Map() : _width(16), _height(16)
{
	entities = std::vector<std::vector<Entity*>>(_height);
	for (int i = 0; i < _height; ++i)
	{
		entities[i] = std::vector<Entity*>(_width);
	}
	entities[0][0] = new Village;
}

Map::Map(int width, int height) : _width(width), _height(height) { }

void Map::draw(sf::RenderTarget& target, 
		sf::RenderStates states) const
{
	for (int i = 0; i < _height; ++i)
	{
		for (int j = 0; j < _width; ++j)
		{
			_assets.setTextureRect(sf::IntRect(32,0,16,16)); /* (32,0) é a cordenada do tile de grama. 
															  *	(16,16) é o tamanho do tile */
			_assets.setPosition(j*16, i*16);
			target.draw(_assets, states);
		}
	}
}

int Map::get_width() const
{
	return _width;
}

int Map::get_height() const
{
	return _height;
}
