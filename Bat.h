#pragma once
#include <SFML/Graphics.hpp>

//using namespace sf;

class Bat
{
private:
	// Čuva trenutnu poziciju bata u 2D prostoru (x i y koordinate).
	// Ova pozicija se koristi za logiku kretanja i pomeranja bata,
	// a zatim se prenosi na m_Shape da bi se bat pomerio na ekranu.
	sf::Vector2f m_Position;

	// Pravougaoni oblik koji predstavlja vizuelni izgled bata u igri.
	// SFML koristi ovaj objekat za crtanje bata na ekranu.
	// Njegova veličina, boja i pozicija se postavljaju u odnosu na m_Position.
	sf::RectangleShape m_Shape;

	// Brzina kretanja bata u pikselima po sekundi.
	float m_Speed = 1000.0f;

	// Statusi koji označavaju da li se bat trenutno kreće levo ili desno.
	bool m_MovingRight = false;
	bool m_MovingLeft = false;
	//test
	bool m_MovingUp = false;
	bool m_MovingDown = false;

public:
	// Konstruktor klase Bat – postavlja početnu poziciju bata na ekranu.
	// startX i startY su koordinate na koje će se bat pojaviti kad igra krene.
	Bat(float startX, float startY);

	// Vraća pravougaoni okvir (poziciju i dimenzije) bata.
	// Koristi se za detekciju sudara sa drugim objektima, kao što je loptica.
	sf::FloatRect getPosition();

	// Vraća pravougaoni oblik bata (m_Shape) koji se koristi za crtanje.
	// Ova metoda omogućava da se bat nacrta u glavnom prozoru (window).
	sf::RectangleShape getShape();

	void moveLeft();
	void moveRight();

	// Test for moving up and down
	void moveUp();
	void moveDown();
	void stopUp();
	void stopDown();

	void stopLeft();
	void stopRight();

	bool isMovingLeft();
	bool isMovingRight();

	bool isMovingUp();
	bool isMovingDown();

	// Ažurira poziciju bata na osnovu brzine i vremena.
	// Pomera bata levo ili desno ako su pokrenuti odgovarajući statusi.
	void update(sf::Time dt);
};
