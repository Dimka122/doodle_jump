#include"Doodle.h"

C_Doodle::C_Doodle()
{
	m_Speed = 400;

	m_texture.loadFromFile("doodle.png");
	m_sprite.setTexture(m_texture);

	m_Position.x = 300;
	m_Position.y = 300;
}
Sprite C_Doodle::getSprite()
{
	return m_sprite;
}
void C_Doodle::moveLeft()
{
	m_LeftPressed = true;
}
void C_Doodle::moveRight()
{
	m_RightPressed = true;
}