#include<SFML/Graphics.hpp>

using namespace sf;

int main()
{
	RenderWindow window(VideoMode(400, 400), "SFML works");

	while (window.isOpen())
	{
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)

				window.close();
		}

		window.display();
	}
	return 0;
}