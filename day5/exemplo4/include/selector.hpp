#ifndef _SELECTOR_HPP_
#define _SELECTOR_HPP_

#include "entity.hpp"

class Selector : public Entity, public sf::Drawable
{
public:
	Selector();
	void handle_input(sf::Event event);
private:
	//bool _selected = false;
	virtual void draw(sf::RenderTarget& target, 
		sf::RenderStates states) const override;
};

#endif /* SELECTOR_HPP_ */
