#ifndef _MAP_HPP_
#define _MAP_HPP_

#include <SFML/Graphics.hpp>
#include "entity.hpp"
#include "village.hpp"

class Map : public sf::Drawable, public Entity
{
public:
	Map(const Map&) = delete;
	Map& operator=(const Map&) = delete;
	Map();
	Map(int width, int height);
	int get_width() const;
	int get_height() const;
private:
	int _width;
	int _height;
	std::vector<std::vector<Entity*>> entities;
	virtual void draw(sf::RenderTarget& target, 
		sf::RenderStates states) const override;
};

#endif /* _MAP_HPP_ */
