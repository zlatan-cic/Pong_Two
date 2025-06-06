#include "Bat.h"
#include <iostream>


// Ovo je konstruktor i zove se kad kreiramo objekat // "initializer list" konstruktor // 
// Konstruktor klase Bat – koristi initializer list da odmah postavi početnu poziciju bata.
// startX i startY su koordinate gde će se bat pojaviti na ekranu.
// m_Position se inicijalizuje kao sf::Vector2f(startX, startY)
Bat::Bat(float startX, float startY) : m_Position(startX, startY)
{
	// Postavlja veličinu vizuelnog oblika bata na 150x50 piksela.
	// 150 je širina (x), 50 je visina (y).
	// Ova dimenzija se koristi za crtanje bata na ekranu.	
	m_Shape.setSize(sf::Vector2f(150, 20));

	// Postavlja vizuelnu poziciju m_Shape da odgovara logičkoj poziciji m_Position.
	// Ovo sinhronizuje izgled bata sa njegovom stvarnom pozicijom u igri.
	m_Shape.setPosition(m_Position);

}

// Vraća pravougaoni okvir bata (poziciju i dimenzije) kao sf::FloatRect.
// Koristi se za detekciju sudara – npr. sa lopticom u igri.
// Koristi SFML-ovu metodu getGlobalBounds() da dobije aktuelni hitbox m_Shape-a.
sf::FloatRect Bat::getPosition()
{
	return m_Shape.getGlobalBounds();
}

// Vraća pravougaoni oblik bata (m_Shape), koji se koristi za crtanje na ekranu.
// Ova funkcija omogućava glavnoj petlji igre da nacrta bata pomoću window.draw().
sf::RectangleShape Bat::getShape()
{
	return m_Shape;
}

void Bat::moveLeft()
{
	m_MovingLeft = true;
}

void Bat::moveRight()
{
	m_MovingRight = true;
}

void Bat::stopLeft()
{
	m_MovingLeft = false;
}

void Bat::stopRight()
{
	m_MovingRight = false;
}

// test
void Bat::moveUp()
{
	m_MovingUp = true;
}

void Bat::moveDown()
{
	m_MovingDown = true;
}

void Bat::stopUp()
{
	m_MovingUp = false;
}

void Bat::stopDown()
{
	m_MovingDown = false;
}

bool Bat::isMovingLeft()
{
	return m_MovingLeft;
}

bool Bat::isMovingRight()
{
	return m_MovingRight;
}

bool Bat::isMovingUp()
{
	return m_MovingUp;
}

bool Bat::isMovingDown()
{
	return m_MovingDown;
}

// Ažurira poziciju bata na osnovu trenutnog stanja kretanja (levo/desno).
// Kretanje se skalira u odnosu na proteklo vreme (dt) da bi bilo konstantno bez obzira na FPS.
// Na kraju se nova pozicija primenjuje na vizuelni oblik (m_Shape).
void Bat::update(sf::Time dt) {
	if (m_MovingLeft) {
		m_Position.x -= m_Speed * dt.asSeconds();
	}
	if (m_MovingRight)
	{
		m_Position.x += m_Speed * dt.asSeconds();
	}
	if (m_MovingUp)
	{
		m_Position.y -= m_Speed * dt.asSeconds();
	}
	if (m_MovingDown)
	{
		m_Position.y += m_Speed * dt.asSeconds();
	}

	m_Shape.setPosition(m_Position);
	// test for git
}