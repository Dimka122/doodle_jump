#include<SFML/Graphics.hpp>

using namespace sf;

class DooDle {
private:
	float x, y;
public:
	float w, h, dx, dy, speed;
	int dir;
	String File;
	Image image;
	Texture texture;
	Sprite sprite;

	DooDle(String F, float X, float Y, float W, float H) {
		dx = 0; dy = 0; speed = 0; dir = 0;
		File = F;
		w = W; h = H;
		image.loadFromFile("image" + File);
		image.createMaskFromColor(Color(41, 33, 59));
		texture.loadFromImage(image);
		sprite.setTexture(texture);
		x = X; y = Y;
		sprite.setTextureRect(IntRect(0, 0, w, h));
	}
	void update(float time) {
		switch (dir)
		{
		case 0:dx = speed; dy = 0; break;
		case 1:dx = -speed; dy = 0; break;
		}
		x += dx * time;
		y += dy * time;

		speed = 0;
		sprite.setPosition(x, y);
		interactionWithMap();
	}
	float getplayercoordinateX() {
		return x;
	}
	float getplayercoordinateY() {
		return y;
	}
	void interactionWithMap()
	{
		for(int i=y/32;i<(y+h)/32;i++)
			for(int j=x/32;j<(x+w)/32;j++)
			{
				
			}
	}
};
