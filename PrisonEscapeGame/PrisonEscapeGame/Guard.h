#pragma once
#pragma once

#include <SFML/Graphics.hpp>

enum guardState { guardIDLE, guardDESTINATION, guardCHASE }; // moving idly, walking to destination, and chasing the player

class Guard
{
public:
	Guard();
	~Guard();
	enum GuardDir { Up, Left, Down, Right, Idle };

	GuardDir lastGuardPosition = Down;


	sf::Sprite guardSprite;
	sf::Texture guardTexture;

	sf::Clock GuardClock;
	int guardTime = 0;
	int guardMove = 0; // the random number generated to see which state the prisoner is in
	int guardHealth = 200;


	void drawGuard(sf::RenderWindow &window);
	void guardState();
	void moveGuard(char direction, float moveSpeed);
};
