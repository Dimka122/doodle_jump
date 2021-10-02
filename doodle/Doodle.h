#pragma once
#include<SFML/Graphics.hpp>

using namespace sf;

class C_Doodle:public RenderWindow
{
	Vector2f m_Position;
	Sprite m_sprite;
	Texture m_texture;

	bool m_LeftPressed;
	bool m_RightPressed;

	float m_Speed;
public:
	C_Doodle();

	Sprite getSprite();
	void moveLeft();
	void moveRight();

	void stopLeft();
	void stopRight();

	void update(float elapsedTime);
};