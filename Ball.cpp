#include "Ball.h"

// Construcotr fun.

Ball::Ball(float startX, float startY) : m_Position(startX, startY)
{
	m_Shape.setSize(sf::Vector2f(20, 20)); // Veličina loptice: 30x30 piksela
	m_Shape.setPosition(m_Position);  // Postavlja oblik na početnu poziciju
}

FloatRect Ball::getPosition()
{
	return m_Shape.getGlobalBounds();
}


RectangleShape Ball::getShape()
{
	return m_Shape;
}

float Ball::getXvelocity()
{
	return m_DirectionX;
}

void Ball::reboundSides()
{
	m_DirectionX = -m_DirectionX;
}

void Ball::reboundBatOrTop()
{
	m_DirectionY = -m_DirectionY;
}

void Ball::reboundBottom()
{
	m_Position.y = 100;
	m_Position.x = 500;

	m_DirectionY = .2f;
	//m_DirectionY = -m_DirectionY;
	m_Shape.setPosition(m_Position);
}

void Ball::update(Time dt)
{
	//Anzuriranje loptice tj pozicija
	m_Position.y += m_DirectionY * m_Speed * dt.asSeconds();
	m_Position.x += m_DirectionX * m_Speed * dt.asSeconds();

	// Pomeraj lopticu
	m_Shape.setPosition(m_Position);
}