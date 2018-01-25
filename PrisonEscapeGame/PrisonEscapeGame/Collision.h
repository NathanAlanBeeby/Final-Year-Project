#pragma once
#include <SFML\Graphics.hpp>

class Collision {
public:
	Collision(sf::RectangleShape& body);

	void move(float dx, float dy) { body.move(dx, dy); }

	bool onCollision(Collision& other, float push, sf::Vector2f& direction);

	sf::Vector2f GetPosition() { return body.getPosition(); }

	sf::Vector2f GetHalfExtent() { return body.getSize() / 2.0f; }

private:
	sf::RectangleShape& body;
};