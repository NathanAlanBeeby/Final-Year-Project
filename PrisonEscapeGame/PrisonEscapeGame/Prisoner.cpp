#include "Prisoner.h"
#include <iostream>


Prisoner::Prisoner(sf::Vector2f size, sf::Vector2f position)
{
	if (!prisonerTexture.loadFromFile("../assets/image_assets/characters/prisoner_images.png")) {
		std::cout << "Error could not load prisoner texture" << std::endl;
		system("pause");
	}

	prisonerSprite.setSize(size);
	prisonerSprite.setOrigin(size / 2.0f);
	prisonerSprite.setTexture(&prisonerTexture);
	prisonerSprite.setPosition(position);

}


Prisoner::~Prisoner()
{
}


enum PrisonerDir { Down, Right, Up, Left, Idle };
PrisonerDir lastPrisonerPosition = Down;
sf::Vector2i PrisonAnim(1, Down);



void Prisoner::drawPrisoner(sf::RenderWindow &window) {

	prisonerState::IDLE;
	vel.x = 0;
	vel.y = 0;

	

	std::string SecondsString = std::to_string(prisonTime);
	sf::Time TimeElapsed = PrisonClock.getElapsedTime(); // setting the time to the hud clock, so it can count seconds
	sf::Time seconds = sf::seconds(1); // this is to compare to the time elapsed to get 1 second


	

	if (TimeElapsed >= seconds) { // if the time elapsed is a second, increment the HUDTime and restart the HUDClock 
		prisonTime++;
		PrisonClock.restart();
		//std::cout << "Minutes: " << HUDTimeMinute << ", Seconds: " << HUDTime << std::endl;
		std::cout << prisonTime << std::endl;
	}

	if (prisonerState::IDLE) {
		if (prisonTime >= 5) {
			PrisonMove = rand() % 6; // a random number generator between 1 and 8
			prisonTime = 0;
		}



		if (PrisonMove == 1) {
			if (prisonerSprite.getPosition().y > 64) {
				vel.y -= moveSpeed;
				PrisonAnim.y = Up;
				lastPrisonerPosition = Up;
			}
		}
		else if (PrisonMove == 2) {
			if (prisonerSprite.getPosition().x > 64) {
				vel.x -= moveSpeed;
				PrisonAnim.y = Left;
				lastPrisonerPosition = Left;
			}
		}
		else if (PrisonMove == 3) {
			if (prisonerSprite.getPosition().y < 4416) {
				vel.y += moveSpeed;
				PrisonAnim.y = Down;
				lastPrisonerPosition = Down;
			}
		}
		else if (PrisonMove == 4) {
			if (prisonerSprite.getPosition().x < 2752) {
				vel.x += moveSpeed;
				PrisonAnim.y = Right;
				lastPrisonerPosition = Right;
			}
		}
		else {
			PrisonAnim.y = Idle;
			lastPrisonerPosition = Idle;
		}

	}
	
		prisonerSprite.move(vel.x, vel.y);

		PrisonAnim.x++;
		if (PrisonAnim.x * 32 >= prisonerTexture.getSize().x) { // once the sprite reaches the end of the sprite sheet, reset to 0 again
			PrisonAnim.x = 0;
		}

		prisonerSprite.setTextureRect(sf::IntRect(PrisonAnim.x * 32, PrisonAnim.y * 32, 32, 32)); // cropping the image with the position and size of the image 

		if (prisonerHealth > 0) {
			window.draw(prisonerSprite);
		}
	//	sf::Vector2f prisonerSize(64, 64);
		//Collision(prisonerPosition, prisonerSize);
}



void Prisoner::prisonerState() {

}

//void Prisoner::Collision(sf::Vector2f prisonerPosition, sf::Vector2f Size) {
	//std::cout << "Prisoner Position - X: " << prisonerPosition.x << ", Y:" << prisonerPosition.y << std::endl; // getting the prisoner position and size to get the collision bounds
	//std::cout << "Prisoner Size - X: " << Size.x << ", Y:" << Size.y << std::endl;
//}
void Prisoner::onCollision(sf::Vector2f direction)
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