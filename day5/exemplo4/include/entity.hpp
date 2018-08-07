#ifndef _ENTITY_HPP_
#define _ENTITY_HPP_

#include <SFML/Graphics.hpp>

#ifndef MAP_WIDTH
#define MAP_WIDTH 24
#endif

#ifndef MAP_HEIGHT
#define MAP_HEIGHT 24
#endif

enum Color
{
	BLUE, RED, YELLOW, GREEN, WHITE
};

class Entity 
{
public:
	Entity(int x=0, int y=0);
	virtual ~Entity() = default;
	static sf::Texture _texture;
	static sf::Sprite _assets;
	void set_x(int x);
	void set_y(int y);
	int get_x() const;
	int get_y() const;
	bool is_selected() const;
	void set_selected(bool selected);
protected:
	int _x;
	int _y;
	bool _selected;
};

#endif /* _ENTITY_HPP_ */
