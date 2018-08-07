#include "d5exemplo1.h"
#include <SFML/Graphics.hpp>

void handle_input(sf::Event event, sf::RenderWindow & window);
void draw();

int main()
{
	sf::RenderWindow window(sf::VideoMode(1000, 800),
		"Village War");
	while(window.isOpen())
	{
		sf::Event event;
		while(window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				window.close();
			}
			handle_input(event, window);
		}
		window.clear(sf::Color::Black);
		draw();
		window.display();
	}
	return 0;
}

void handle_input(sf::Event event, sf::RenderWindow & window)
{
	if (event.type == sf::Event::KeyPressed)
	{
		switch(event.key.code)
		{
			case sf::Keyboard::Escape:
			{
				window.close();
				break;
			}
			// Insira aqui o código para outras teclas pressionadas
			// Para ver a lista de teclas acesse:
			// https://www.sfml-dev.org/documentation/2.5.0/classsf_1_1Keyboard.php#acb4cacd7cc5802dec45724cf3314a142
			default:
				break;
		}
	}
}

void draw()
{
	// Instancie aqui os objetos Drawable
}
