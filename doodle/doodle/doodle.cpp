#include<SFML/Graphics.hpp>
#include<time.h>
#include<iostream>
#include<sstream>
#include"DooDle.h"
#include"Map.h"
#include"viev.h"



using namespace sf;

struct point {
	int x;
	int y;
};
int main()
{
	int healt = 0;
	srand(time(0));

	RenderWindow app(VideoMode(400,533), "Doodle_jump");
	viev.reset(sf::FloatRect(0, 0, 400, 533));
	app.setFramerateLimit(60);

	Font font;
	font.loadFromFile("image/Stick.ttf");
	Text text("",font, 20);
	//text.setColor(Color::Black);
	text.setStyle(Text::Bold);

	Texture t1, t2, t3,t4;
	t1.loadFromFile("image/background.png");
	t2.loadFromFile("image/platform.png");
	t3.loadFromFile("image/doodle.png");
	t4.loadFromFile("image/Stick.ttf");
	DooDle p("image/doodle.png", 250, 250, 96.0, 96.0);

	Sprite sBackground(t1), sPlat(t2), p(t3);

	point plat[25];

	for (int i = 0; i < 10; i++)
	{
		plat[i].x = rand() % 400;
		plat[i].y = rand() % 533;
	}

	int x = 100, y = 100, h = 200;
	float dx = 0, dy = 0;

	Clock clock;

	while (app.isOpen())
	{
		Event event;
		while (app.pollEvent(event))
		{
			if (event.type == Event::Closed)
				app.close();
		}

		if (Keyboard::isKeyPressed(Keyboard::Right))x += 3;
		if (Keyboard::isKeyPressed(Keyboard::Left))x -= 3;

		dy += 0.2;
		y += dy;
		if (y > 500)dy-= 10;

		if(y<h)
			for (int i = 0; i < 10; i++)
			{
				y = h;
				plat[i].y = plat[i].y - dy;
				if (plat[i].y > 533) { plat[i].y = 0; plat[i].x = rand() % 400; }
			}
		for(int i=0;i<10;i++)
			if((x+50>plat[i].x)&&(x+20<plat[i].x+68)
				&& (y + 70 > plat[i].y) && (y + 70 < plat[i].y + 14) && (dy > 0))dy = -10;

		sPers.setPosition(x, y);

		app.draw(sBackground);
		app.draw(sPers);
		for (int i = 0; i < 10; i++)
		{
			sPlat.setPosition(plat[i].x, plat[i].y);
			app.draw(sPlat);
		}
		int healt = 1;
		++healt;
		std::ostringstream playerHealtString;
		playerHealtString << healt;
		text.setString("POINTS:" + playerHealtString.str());
		std::cout << ++healt;

		app.draw(text); 

		app.display();
	}
	return 0;
}