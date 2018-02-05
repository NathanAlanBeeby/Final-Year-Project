#include "Guard.h"
#include <iostream>

Guard::Guard(sf::Vector2f size, sf::Vector2f position)
{
	if (!guardTexture.loadFromFile("../assets/image_assets/characters/guard_images.png")) {
		std::cout << "Error could not load guard texture" << std::endl;
		system("pause");
	}
	guardSprite.setSize(size);
	guardSprite.setOrigin(size / 2.0f);
	guardSprite.setTexture(&guardTexture);
	guardSprite.setPosition(position);

}


Guard::~Guard()
{
}


enum GuardDir { Down, Right, Up, Left, Idle };
GuardDir lastGuardPosition = Down;
sf::Vector2i GuardAnim(1, Down);



void Guard::drawGuard(sf::RenderWindow &window) {

	guardState::guardIDLE; // setting the player defaultly to IDLE
	vel.x = 0;
	vel.y = 0;

	std::string SecondsString = std::to_string(guardTime);
	sf::Time TimeElapsed = GuardClock.getElapsedTime(); // setting the time to the hud clock, so it can count seconds
	sf::Time seconds = sf::seconds(1); // this is to compare to the time elapsed to get 1 second


	if (TimeElapsed >= seconds) { // if the time elapsed is a second, increment the HUDTime and restart the HUDClock 
		guardTime++;
		GuardClock.restart();
		//std::cout << "Minutes: " << HUDTimeMinute << ", Seconds: " << HUDTime << std::endl;
		std::cout << guardTime << std::endl;
	}

	if (guardState::guardIDLE) {
		if (guardTime >= 2) {
			guardMove = rand() % 6; // a random number generator between 1 and 8
			guardTime = 0;
		}

		if (guardMove == 1) {
			if (guardSprite.getPosition().y < 4352) {
				vel.y -= moveSpeed;
				GuardAnim.y = Up;
				lastGuardPosition = Up;
			}
		}
		else if (guardMove == 2) {
			if (guardSprite.getPosition().x > 64) {
				vel.x -= moveSpeed;
				GuardAnim.y = Left;
				lastGuardPosition = Left;
			}
		}
		else if (guardMove == 3) {
			if (guardSprite.getPosition().y > 64) {
				vel.y += moveSpeed;
				GuardAnim.y = Down;
				lastGuardPosition = Down;
			}
		}
		else if (guardMove == 4) { // Right Facing Prisoner
			if (guardSprite.getPosition().x < 2752) {
				vel.x += moveSpeed;
				GuardAnim.y = Right;
				lastGuardPosition = Right;
			}
		}
		else {
			GuardAnim.y = Idle;
			lastGuardPosition = Idle;
		}
	}

	guardSprite.move(vel.x, vel.y);
	GuardAnim.x++;
	if (GuardAnim.x * 32 >= guardTexture.getSize().x) { // once the sprite reaches the end of the sprite sheet, reset to 0 again
		GuardAnim.x = 0;
	}

	guardSprite.setTextureRect(sf::IntRect(GuardAnim.x * 32, GuardAnim.y * 32, 32, 32)); // cropping the image with the position and size of the image 

	if(guardHealth > 0){

	window.draw(guardSprite);
	
	}
	
	
	//sf::Vector2f guardSize(64, 64);

	//Collision(guardPosition, guardSize);
}

//void Guard::Collision(sf::Vector2f guardPosition, sf::Vector2f Size) {
//	//std::cout << "Guard Position - X: " << guardPosition.x << ", Y:" << guardPosition.y << std::endl; //getting the guards position for collision
//	//std::cout << "Guard Size - X: " << Size.x << ", Y:" << Size.y << std::endl;
//}

void Guard::guardState() {

}
void Guard::onCollision(sf::Vector2f direction)
{
	if (direction.x < 0.0f) {
		//colliding on the left side so set velocity to 0 to stop movement
		vel.x = 0.0f;
	}
	else if (direction.x > 0.0f) {
		//colliding on the right
		vel.x = 0.0f;
	}

	if (direction.y < 0.0f) {
		//colliding on the bottom
		vel.y = 0.0f;

	}
	else if (direction.y > 0.0f) {
		//colliding on top
		vel.y = 0.0f;
	}
}