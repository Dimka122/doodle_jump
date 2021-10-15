#include<SFML/Graphics.hpp>
#include<time.h>
#include<iostream>
#include<sstream>
#include"DooDle.h"
#include"Map.h"
#include"viev.h"



using namespace sf;

/*struct point
{
	float x;
	float y;
};*/ 

int main()
{
	srand(time(0));

	RenderWindow app(VideoMode(400,533), "Doodle_jump");
	viev.reset(sf::FloatRect(0, 0, 400, 533));
	app.setFramerateLimit(60);

	Texture t1, t2, t3;
	t1.loadFromFile("image/background.png");
	t2.loadFromFile("image/platform.png");
	t3.loadFromFile("image/doodle.png");
	DooDle p("image/doodle.png", 250, 250, 96.0, 96.0);

	Sprite sBackground(t1), sPlat(t2), p(t3);

	sPlat[30];

	for (int i = 0; i < 10; i++)
	{
		sPlat[i].x = rand() % 400;
		sPlat[i].y = rand() % 533;
	}

	int x = 100, y = 100, h = 200;
	float dx = 0, dy = 0;

	float CurrentFrame = 0;
	Clock clock;

	while (app.isOpen())
	{
		float time = clock.getElapsedTime().asMicroseconds();
		clock.restart();
		time = time / 800;

		Event event;
		while (app.pollEvent(event))
		{
			if (event.type == Event::Closed)
				app.close();
		}

		if (Keyboard::isKeyPressed(Keyboard::Right)) {
			p.dir = 1; p.speed = 0.1;
			CurrentFrame += 0.005 * time;
			if (CurrentFrame > 3)CurrentFrame -= 3;
			p.sprite.setTextureRect(IntRect(96 * int(CurrentFrame), 192, 96, 96));
			getplaercoordinateforviev(p.getplayercoordinateX(), p.getplayercoordinateY());
		}
		if (Keyboard::isKeyPressed(Keyboard::Left)) {
			p.dir = 1; p.speed = 0.1;
			CurrentFrame += 0.005 * time;
			if (CurrentFrame > 3)CurrentFrame -= 3;
			p.sprite.setTextureRect(IntRect(96 * int(CurrentFrame), 96, 96, 96));
		}
			getplaercoordinateforviev(p.getplayercoordinateX(), p.getplayercoordinateY());
		
		p.update(time);
		vievmap(time);
		app.setView(viev);
		app.clear();

		dy += 0.2;
		y += dy;
		if (y > 500)dy-= 10;

		if(y<h)
			for (int i = 0; i < 10; i++)
			{
				y = h;
				sPlat[i].y = sPlat[i].y - dy;
				if (sPlat[i].y > 533) { sPlat[i].y = 0; sPlat[i].x = rand() % 400; }
			}
		for(int i=0;i<10;i++)
			if((x+50>sPlat[i].x)&&(x+20<sPlat[i].x+68)
				&& (y + 70 > sPlat[i].y) && (y + 70 < sPlat[i].y + 14) && (dy > 0))dy = -10;

		p.update(time);

		app.draw(sBackground);
		//app.draw(t3);
		for (int i = 0; i < 10; i++)
		{
			sPlat.setPosition(sPlat[i].x, sPlat[i].y);
			app.draw(sPlat);
		}
		/*int healt = 1;
		++healt;
		std::ostringstream playerHealtString;
		playerHealtString << healt;
		//text.setString("POINTS:" + playerHealtString.str());
		std::cout << ++healt;

		//app.draw(text);*/ 

		app.display();
	}
	return 0;
}