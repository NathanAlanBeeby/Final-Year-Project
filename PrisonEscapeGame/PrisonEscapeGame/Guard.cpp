#include "Guard.h"
#include <iostream>

Guard::Guard()
{
	guardSprite.setPosition(100, 200);

}


Guard::~Guard()
{
}




void Guard::drawGuard(sf::RenderWindow &window) {
	sf::Vector2i GuardAnim(1, Down);

	if (!guardTexture.loadFromFile("../assets/image_assets/guard_images.png")) {
		std::cout << "Error could not load prisoner texture" << std::endl;
		system("pause");
	}


	guardSprite.setTexture(guardTexture);

	 guardPosition.x = guardSprite.getPosition().x;
	 guardPosition.y = guardSprite.getPosition().y;


	int guardState = guardIDLE; // setting the player defaultly to IDLE



	std::string SecondsString = std::to_string(guardTime);
	sf::Time TimeElapsed = GuardClock.getElapsedTime(); // setting the time to the hud clock, so it can count seconds
	sf::Time seconds = sf::seconds(1); // this is to compare to the time elapsed to get 1 second


	if (TimeElapsed >= seconds) { // if the time elapsed is a second, increment the HUDTime and restart the HUDClock 
		guardTime++;
		GuardClock.restart();
		//std::cout << "Minutes: " << HUDTimeMinute << ", Seconds: " << HUDTime << std::endl;
		std::cout << guardTime << std::endl;
	}


	if (guardTime >= 2) {
		guardMove = rand() % 6; // a random number generator between 1 and 8
		guardTime = 0;
	}

	int Speed = 10;


	if (guardMove == 1) { // Up Facing prisoner
		if (guardSprite.getPosition().y < 4352) {
			GuardAnim.y = Down;
			moveGuard('u', Speed);
			lastGuardPosition = Down;
		}
	}
	else if (guardMove == 2) { // Down Facing Prisoner
		if (guardSprite.getPosition().x > 64) {
			GuardAnim.y = Left;
			moveGuard('l', Speed);
			lastGuardPosition = Left;
		}
	}
	else if (guardMove == 3) { // Left Facing Prisoner
		if (guardSprite.getPosition().y > 64) {
			GuardAnim.y = Up;
			moveGuard('d', Speed);
			lastGuardPosition = Up;
		}
	}
	else if (guardMove == 4) { // Right Facing Prisoner
		if (guardSprite.getPosition().x < 2752) {
			GuardAnim.y = Right;
			moveGuard('r', Speed);
			lastGuardPosition = Right;
		}
	}
	else {
		GuardAnim.y = Idle;
		moveGuard('a', Speed);
		lastGuardPosition = Idle;
	}

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

void Guard::moveGuard(char direction, float moveSpeed) {
	if (direction == 'u') {
		guardSprite.move(0, -moveSpeed);
	}
	else if (direction == 'd') {
		guardSprite.move(0, moveSpeed);
	}
	if (direction == 'l') {
		guardSprite.move(-moveSpeed, 0);
	}
	else if (direction == 'r') {
		guardSprite.move(moveSpeed, 0);
	}
	else if (direction == 'a') {
		guardSprite.move(0, 0);
	}
}