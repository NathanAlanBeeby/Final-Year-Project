#pragma once

#include <SFML/Graphics.hpp>
#include "HUD.h"
#include "Collision.h"

enum prisonerState { IDLE, prisonerStop, prisonerAngry, DESTINATION, CHASE }; // moving idly, walking to destination, and chasing the player

class Prisoner
{
public:
	Prisoner(sf::Vector2f size, sf::Vector2f position);
	~Prisoner();
	
	HUD hud;


	float moveSpeed = 15;
	sf::Vector2f vel;


	sf::Texture prisonerTexture;
	sf::RectangleShape prisonerSprite;

	sf::Vector2f getPosition() { return prisonerSprite.getPosition(); }

	Collision getCollision() { return Collision(prisonerSprite); }

	//void Collision(sf::Vector2f prisonerPosition, sf::Vector2f Size);
	float Speed = 7.5;
	sf::Clock PrisonClock;
	int prisonTime = 0;
	int PrisonMove = 0; // the random number generated to see which state the prisoner is in
	int prisonerHealth = 100;
	

	void drawPrisoner(sf::RenderWindow &window);
	void prisonerState();
	void onCollision(sf::Vector2f direction);

};

