#include<SFML/Graphics.hpp>
using namespace sf;

sf::View viev;
void getplaercoordinateforviev(float x, float y) {
	viev.setCenter(x + 100, y);
}
