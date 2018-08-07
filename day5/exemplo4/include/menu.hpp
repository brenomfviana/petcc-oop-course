#ifndef _MENU_HPP_
#define _MENU_HPP_

#include <SFML/Graphics.hpp>
#include "entity.hpp"
#include "unit.hpp"
#include "village.hpp"

class Menu : public sf::Drawable
{
public:
	Menu();
	void handle_input(sf::Event event);
	void set_msg(sf::String msg);
	void set_msg(char* msg);
	void set_entity(Entity* entity);
private:
	sf::String _msg;
	Entity* _entity; //< Entidade cujas opções vão ser exibidas
	virtual void draw(sf::RenderTarget& target, 
		sf::RenderStates states) const override;
};


#endif /* _MENU_HPP_ */
