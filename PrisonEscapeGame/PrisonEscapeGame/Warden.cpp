#include "Warden.h"
#include <iostream>


Warden::Warden(sf::Vector2f size, sf::Vector2f position)
{
	if (!WardenTexture.loadFromFile("../assets/image_assets/characters/warden_images.png")) {
		std::cout << "Error could not load guard texture" << std::endl;
		system("pause");
	}
	WardenSprite.setSize(size);
	WardenSprite.setOrigin(size / 2.0f);
	WardenSprite.setTexture(&WardenTexture);
	WardenSprite.setPosition(position);
}


Warden::~Warden()
{
}



enum WardenDir { Down, Right, Up, Left, Idle };
WardenDir lastWardenPosition = Down;
sf::Vector2i WardenAnim(1, Down);



void Warden::drawWarden(sf::RenderWindow &window) {

	wardenState::wardenIDLE; // setting the player defaultly to IDLE
	vel.x = 0;
	vel.y = 0;

	std::string SecondsString = std::to_string(WardenTime);
	sf::Time TimeElapsed = WardenClock.getElapsedTime(); // setting the time to the hud clock, so it can count seconds
	sf::Time seconds = sf::seconds(1); // this is to compare to the time elapsed to get 1 second


	if (TimeElapsed >= seconds) { // if the time elapsed is a second, increment the HUDTime and restart the HUDClock 
		WardenTime++;
		WardenClock.restart();
	
		std::cout << WardenTime << std::endl;
	}

	if (wardenState::wardenIDLE) {
		if (WardenTime >= 2) {
			WardenMove = rand() % 6; // a random number generator between 1 and 8
			WardenTime = 0;
		}

		if (WardenMove == 1) {
			if (WardenSprite.getPosition().y < 4352) {
				vel.y -= moveSpeed;
				WardenAnim.y = Up;
				lastWardenPosition = Up;
			}
		}
		else if (WardenMove == 2) {
			if (WardenSprite.getPosition().x > 64) {
				vel.x -= moveSpeed;
				WardenAnim.y = Left;
				lastWardenPosition = Left;
			}
		}
		else if (WardenMove == 3) {
			if (WardenSprite.getPosition().y > 64) {
				vel.y += moveSpeed;
				WardenAnim.y = Down;
				lastWardenPosition = Down;
			}
		}
		else if (WardenMove == 4) { // Right Facing warden
			if (WardenSprite.getPosition().x < 2752) {
				vel.x += moveSpeed;
				WardenAnim.y = Right;
				lastWardenPosition = Right;
			}
		}
		else {
			WardenAnim.y = Idle;
			lastWardenPosition = Idle;
		}
	}

	WardenSprite.move(vel.x, vel.y);
	WardenAnim.x++;
	if (WardenAnim.x * 32 >= WardenTexture.getSize().x) { // once the sprite reaches the end of the sprite sheet, reset to 0 again
		WardenAnim.x = 0;
	}

	WardenSprite.setTextureRect(sf::IntRect(WardenAnim.x * 32, WardenAnim.y * 32, 32, 32)); // cropping the image with the position and size of the image 

	if (WardenHealth > 0) {

		window.draw(WardenSprite);

	}



}


void Warden::WardenState() {

}
void Warden::onCollision(sf::Vector2f direction)
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