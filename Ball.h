#pragma once  
#include <SFML/Graphics.hpp>

using namespace sf;

class Ball
{
private:
	// Pozicija lopte (x i y koordinate)
	Vector2f m_Position;

	// Oblik lopte koji će biti prikazan na ekranu
	RectangleShape m_Shape;

	// Brzina kretanja lopte (piksela po sekundi)
	float m_Speed = 1000.0f;

	// Pravac kretanja lopte po X osi (horizontalno)
	float m_DirectionX = .2f;

	// Pravac kretanja lopte po Y osi (vertikalno)
	float m_DirectionY = .2f;

public:
	// Konstruktor: inicijalizuje početnu poziciju lopte
	Ball(float startX, float startY);

	// Vraća "bounding box" lopte (pravougaonik) – koristi se za detekciju sudara
	FloatRect getPosition();

	// Vraća oblik lopte (RectangleShape) – koristi se za crtanje u main petlji
	RectangleShape getShape();

	// Vraća horizontalnu brzinu lopte (korisno ako želiš da znaš njenu X brzinu)
	float getXvelocity();

	// Kada lopta udari levu ili desnu ivicu – menja horizontalni pravac
	void reboundSides();

	// Kada lopta udari reket ili vrh ekrana – menja vertikalni pravac
	void reboundBatOrTop();

	// Kada lopta padne ispod reketa – resetuje poziciju i pravac
	void reboundBottom();

	// Ažurira poziciju lopte u svakom frame-u (na osnovu pravca i brzine)
	void update(Time dt);
};
