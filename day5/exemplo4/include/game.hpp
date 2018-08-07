#ifndef _WINDOW_HPP_
#define _WINDOW_HPP_

#include <map>
#include <utility>      // std::pair, std::make_pair
#include <SFML/Graphics.hpp>
//#include "entity.hpp"
#include "map.hpp"
#include "selector.hpp"
#include "worker.hpp"
#include "menu.hpp"

class Game
{
public:
	Game();
	void run();
private:
	sf::RenderWindow _window;
	sf::View _view;
	Map mapa;
	Selector sel;
	Menu _menu;
	void handle_input(sf::Event event);
	std::map<std::pair<int,int>, Entity*> entities;
};

#endif /* _WINDOW_HPP_ */
