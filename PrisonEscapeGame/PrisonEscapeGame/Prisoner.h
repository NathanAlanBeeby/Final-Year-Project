#pragma once

#include <SFML/Graphics.hpp>
#include "HUD.h"



enum prisonerState { IDLE, prisonerAngry, DESTINATION, CHASE }; // moving idly, walking to destination, and chasing the player

class Prisoner
{
public:
	Prisoner();
	~Prisoner();
	enum PrisonerDir { Up, Left, Down, Right, Idle };

	PrisonerDir lastPrisonerPosition = Down;
	HUD hud;

	sf::Texture prisonerTexture;
	sf::Sprite prisonerSprite;

	sf::Vector2f prisonerPosition;

	//void Collision(sf::Vector2f prisonerPosition, sf::Vector2f Size);
	float Speed = 7.5;
	sf::Clock PrisonClock;
	int prisonTime = 0;
	int PrisonMove = 0; // the random number generated to see which state the prisoner is in
	int prisonerHealth = 100;
	

	void drawPrisoner(sf::RenderWindow &window);
	void prisonerState();
	void movePrisoner(char direction, float moveSpeed);

};

