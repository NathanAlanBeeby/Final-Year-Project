#include "Collision.h"

using namespace std;

Collision::Collision(sf::RectangleShape& body) :
	body(body) //initializer list
{
}

bool Collision::onCollision(Collision &object, float mass, sf::Vector2f& dir)
{
	sf::Vector2f objectPos = object.GetPosition();
	sf::Vector2f objectHalfExtent = object.GetHalfExtent();
	sf::Vector2f thisPos = GetPosition();
	sf::Vector2f thisHalfExtent = GetHalfExtent();

	float deltaX = objectPos.x - thisPos.x;
	float deltaY = objectPos.y - thisPos.y;

	float intersectX = abs(deltaX) - (objectHalfExtent.x + thisHalfExtent.x);
	float intersectY = abs(deltaY) - (objectHalfExtent.y + thisHalfExtent.y);

	if (intersectX < 0.0f && intersectY < 0.0f) {
		mass = min(max(mass, 0.0f), 1.0f);

		if (intersectX > intersectY) {
			if (deltaX > 0.0f) {
				//this says you are colliding with something on the right of you
				move(intersectX * (1.0f - mass), 0.0f);
				object.move(-intersectX * mass, 0.0f);

				dir.x = 1.0f;
				dir.y = 0.0f;
			}
			else {
				//this means you are colliding with something on the left of you
				move(-intersectX * (1.0f - mass), 0.0f);
				object.move(intersectX * mass, 0.0f);
				dir.x = -1.0f;
				dir.y = 0.0f;
			}
		}
		else {
			if (deltaY > 0.0f) {
				//this states you are colliding with something underneath you
				move(0.0f, intersectY * (1.0f - mass));
				object.move(0.0f, -intersectY * mass);

				dir.x = 0.0f;
				dir.y = 1.0f; //sfml coordinates are flipped so its underneath you
			}
			else {
				move(0.0f, -intersectY * (1.0f - mass));
				object.move(0.0f, intersectY * mass);

				dir.x = 0.0f;
				dir.y = -1.0f;
			}
		}

		return true;
	}
	//clamps mass position to 0-1
	//returns max value of mass and 0
	//min returns value max returns and checks min value of that
	//therefore this is between 0 and 1
	return false;
}
