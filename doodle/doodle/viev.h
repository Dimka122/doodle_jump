#include<SFML/Graphics.hpp>
using namespace sf;

sf::View viev;
void getplaercoordinateforviev(float x, float y) {
	float tempX = x;
	float tempY = y;

	if (x < 320)tempX = 320;
	if (x > 320)tempX = 320;
	if (y < 240)tempY = 240;
	if (y > 554)tempY = 554;

	viev.setCenter(tempX,tempY);
}
void vievmap(float time) {
	if (Keyboard::isKeyPressed(Keyboard::Left)) {
		viev.move(-0.1 * time, 0);
	}
	if (Keyboard::isKeyPressed(Keyboard::Right)) {
		viev.move(0,-0.1 * time);
	}
}