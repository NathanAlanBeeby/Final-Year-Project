#pragma once
#include <SFML\Graphics.hpp>
#include <iostream>



class Collision {
public:
	Collision(sf::RectangleShape& body);

	void move(float dx, float dy) { body.move(dx, dy); }

	bool collision(Collision& other, float push, sf::Vector2f& direction);

	sf::Vector2f GetPosition() { return body.getPosition(); }

	sf::Vector2f GetHalfExtent() { return body.getSize() / 2.0f; }


private:
	sf::RectangleShape& body;
};