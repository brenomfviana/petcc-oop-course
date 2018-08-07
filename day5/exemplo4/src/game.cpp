#include "game.hpp"
#include "village.hpp"
#include <iostream>

Game::Game() : _window(sf::VideoMode(880,660), "Strategy Game", sf::Style::Titlebar | sf::Style::Close),
_view(sf::FloatRect(-180,-138, 880, 660)), mapa(24,24) 
{
	// Empty
}

void Game::run()
{	
	_view.zoom(0.60f);
	_window.setView(_view);
	//Menu menu;

	// A village fill 4 cells
	entities[std::make_pair(0,0)] = new Village;
	entities[std::make_pair(0,1)] = entities[std::make_pair(0,0)];
	entities[std::make_pair(1,1)] = entities[std::make_pair(0,0)];
	entities[std::make_pair(1,0)] = entities[std::make_pair(0,0)];

	entities[std::make_pair(1,2)] = new Worker(RED, 1, 2);
	entities[std::make_pair(2,2)] = new Worker(BLUE, 2, 2);
	entities[std::make_pair(1,3)] = new Worker(GREEN, 1, 3);
	entities[std::make_pair(2,3)] = new Worker(YELLOW, 2, 3);
	
	while(_window.isOpen())
	{
		sf::Event event;
		while(_window.pollEvent(event))
		{
			handle_input(event);
		}
		// Update logic here
		_window.clear(sf::Color(16,16,16,255));
		// Draw here
		_window.draw(mapa);
		_window.draw(_menu);
		for (auto const& e : entities)
		{
			// Trabalhadores
			if (Worker* w = dynamic_cast<Worker*>(e.second))
			   _window.draw(*w);
			// Vilas
			else if (Village* v = dynamic_cast<Village*>(e.second))
			   _window.draw(*v);
		}
		_window.draw(sel);
		_window.display();
	}
}

void Game::handle_input(sf::Event event)
{
	//bool flag = false;
	if (sel.is_selected())
	{
		if (auto e = (Entity*) entities[std::make_pair(sel.get_x(),sel.get_y())])
		{
			_menu.set_entity(e);
		} else
		{
			_menu.set_msg((char *)"Invalid\nSelection\n");
		}
		if ((event.type == sf::Event::KeyPressed) and 
			(event.key.code == sf::Keyboard::Escape))
		{
			sel.set_selected(false);
			_menu.set_entity(new Entity);// to unselect the entity
		}
	}
	/*for (auto const& e : entities)
	{
		if (entities[std::make_pair(sel.get_y(),sel.get_x())] and e.second->is_selected())
		{
			//Menu menu;
			//_window.draw(menu);
			//menu.handle_input(event);
			//e.second->handle_input(event);
			//flag = true;
		}
	}*/
	else
	{
		_menu.set_msg((char *)"Menu\n");
		switch (event.type)
		{
			case sf::Event::Closed:
				_window.close();
				break;
			// Handle the input keys
			case sf::Event::KeyPressed:
			{
				switch(event.key.code)
				{
					case sf::Keyboard::Escape:
						_window.close();
						break;
					default:
						sel.handle_input(event);
						break;
				}
			} break;
			default:
				break;
		}
	}
	/*if (sel.is_selected() and entities[std::make_pair(sel.get_y(),sel.get_x())])
	{
		std::cout << "clicou\n";
		entities[std::make_pair(sel.get_y(),sel.get_x())]->set_selected(true);
		//sel.set_selected(false);
	}*/
}
