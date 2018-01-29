#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>
#include "HUD.h"
#include "Collision.h"
class Player
{

public:
	enum CharMove { Down, Right, Up, Left, Attack };
	CharMove lastPosition = Down;
	sf::Texture spriteTexture;
	sf::Sprite characterSprite;


	//TESTING FOR COLLISION
	sf::Vector2f GetPosition() { return body.getPosition(); }
	Collision GetCollision() { return Collision(body); }
	//TESTING FOR COLLISION




	sf::Vector2f playerPosition;
	//void Collision(sf::Vector2f playerPosition, sf::Vector2f Size);

	HUD hud;
	float moveSpeed = 100;
	
	
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
	
	void movePlayer(char direction, float moveSpeed);

private:
	sf::RectangleShape body;
};

//https://www.youtube.com/watch?v=TJtjH5qKBbs - 21:49 24/11/2017