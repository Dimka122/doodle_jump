#pragma once
#include <SFML/Graphics.hpp>

class MainWindow : public sf::RenderWindow
{
	sf::Texture texture;
	sf::Color _bgColor;
	sf::Sprite sprite;
	sf::IntRect IntRect;
public:
	MainWindow(int width, int heigth) : sf::RenderWindow(sf::VideoMode(width, heigth), "Hello sfml!") {
		_bgColor = sf::Color::Red;
	}
	void show() {
		while (this->isOpen())
		{
			sf::Event event;
			while (this->pollEvent(event))
			{
				if (event.type == sf::Event::Closed) {
					this->close();
				}
			}

			//this->clear(this->_bgColor);
			texture.setRepeated(true);
			texture.loadFromFile("background.png", sf::IntRect(0, 0, 532, 850));
			sf::Sprite sprite(texture);
			this->draw(sprite);
			this->display();
		}
	}

	void setBgColor(int r, int g, int b) {
		this->_bgColor.r = r;
		this->_bgColor.g = g;
		this->_bgColor.b = b;
	}
	void setBgColor(const sf::Color& _color) {
		this->_bgColor = sf::Color(_color);
	}

	~MainWindow() {}
};

