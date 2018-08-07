#include <SFML/Graphics.hpp>

class Game
{
private:
	sf::RenderWindow window;
	sf::RectangleShape player;
public:
	Game() : window(sf::VideoMode(1000, 800),
		"Village War") {}
	
	void run()
	{
		while(window.isOpen())
		{
			sf::Event event;
			while(window.pollEvent(event))
			{
				if (event.type == sf::Event::Closed)
				{
					window.close();
				}
				handle_input(event);
			}
			window.clear(sf::Color::Black);
			draw(window);
			window.display();
		}
	}
	/**
	 * @brief Função para receber os inputs
	 */
	void handle_input(sf::Event event)
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
	/**
	 * @brief Função para desenhar na tela
	 */
	void draw(sf::RenderWindow & window)
	{
		// Instancie aqui os objetos Drawable
		player.setSize(sf::Vector2f(100, 100));
		player.setOutlineColor(sf::Color::Green);
		player.setOutlineThickness(5);
		player.setPosition(50, 50);
		window.draw(player);
	}
};

int main()
{
	Game game;
	game.run();
	return 0;
}

