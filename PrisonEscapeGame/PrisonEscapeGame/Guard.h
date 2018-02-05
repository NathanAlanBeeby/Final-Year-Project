#pragma once

#include <SFML/Graphics.hpp>
#include "Collision.h"
enum guardState { guardIDLE, guardStop, guardDESTINATION, guardCHASE }; // moving idly, walking to destination, and chasing the player

class Guard
{
public:
	Guard(sf::Vector2f size, sf::Vector2f position);
	~Guard();


	sf::Texture guardTexture;
	sf::RectangleShape guardSprite;

	float moveSpeed = 15;
	sf::Vector2f vel;

	//void Collision(sf::Vector2f guardPosition, sf::Vector2f Size);

	
	sf::Clock GuardClock;
	int guardTime = 0;
	int guardMove = 0; // the random number generated to see which state the prisoner is in
	int guardHealth = 200;


	void drawGuard(sf::RenderWindow &window);
	void guardState();
	void onCollision(sf::Vector2f direction);


	sf::Vector2f getPosition() { return guardSprite.getPosition(); }

	Collision getCollision() { return Collision(guardSprite); }


};

