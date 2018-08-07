#ifndef _VILLAGE_HPP_
#define _VILLAGE_HPP_

#include <SFML/Graphics.hpp>
#include "entity.hpp"

class Village : public Entity, public sf::Drawable
{
public:
	Village();
	void my_draw() const;
private:
	virtual void draw(sf::RenderTarget& target, 
		sf::RenderStates states) const override;
};


#endif /* _VILLAGE_HPP_ */
