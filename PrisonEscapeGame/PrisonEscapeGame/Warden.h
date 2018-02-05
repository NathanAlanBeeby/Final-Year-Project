#pragma once
#include <SFML/Graphics.hpp>
#include "Collision.h"
enum wardenState { wardenIDLE, wardenSTOP, wardenDESTINATION }; // moving idly, walking to destination, and chasing the player

class Warden
{
public:
	Warden(sf::Vector2f size, sf::Vector2f position);
	~Warden();

	sf::Texture WardenTexture;
	sf::RectangleShape WardenSprite;

	float moveSpeed = 15;
	sf::Vector2f vel;


	sf::Clock WardenClock;
	int WardenTime = 0;
	int WardenMove = 0; // the random number generated to see which state the prisoner is in
	int WardenHealth = 500;


	void drawWarden(sf::RenderWindow &window);
	void WardenState();
	void onCollision(sf::Vector2f direction);


	sf::Vector2f getPosition() { return WardenSprite.getPosition(); }

	Collision getCollision() { return Collision(WardenSprite); }


};

