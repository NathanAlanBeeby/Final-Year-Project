#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>
#include "HUD.h"

class Player
{
public:
	enum CharMove{Down, Left, Up, Right, Attack};
	
	sf::Texture spriteTexture;
	sf::Sprite characterSprite;


	sf::Vector2f playerPosition;
	//void Collision(sf::Vector2f playerPosition, sf::Vector2f Size);

	HUD hud;
	float moveSpeed = 150;
	
	CharMove lastPosition = Down;
	sf::Clock clock;
	sf::Vector2i ScreenSize;

	int MisOpenCount = 0; // way of knowing if the player has hit the key twice
	int InvOpenCount = 0; // way of knowing if the player has hit the key twice
	int SkilOpenCount = 0; // way of knowing if the player has hit the key twice
	
	Player() {	
		characterSprite.setPosition(120, 120);
		

	}


	void drawPlayer(sf::View view, sf::RenderWindow &window);
	void playerKeyboardMovement(sf::View &view, sf::RenderWindow &window);
	void PlayerMouseInput(sf::RenderWindow &window);
	void movePlayer(char direction, float moveSpeed);

private:
};

//https://www.youtube.com/watch?v=TJtjH5qKBbs - 21:49 24/11/2017