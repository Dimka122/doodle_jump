#include<SFML/Graphics.hpp>
#include <iostream>
#include"MainWindow.h"

using namespace sf;





int main()
{
	//RenderWindow window(VideoMode(400, 400), "SFML works");

	/*while (window.isOpen())
	{
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)

				window.close();
		}
		
		window.display();
	}


	return 0;*/ 
	MainWindow * window = new MainWindow(532, 850);
	window->setBgColor(127, 176, 48);
	//window->setBgColor(sf::Color::Green);
	window->show();
	window->show();
	window->show();


	delete window;
	return 0;
}
