#include "Prisoner.h"
#include <iostream>


Prisoner::Prisoner()
{
	prisonerSprite.setPosition(100, 100);

}


Prisoner::~Prisoner()
{
}




void Prisoner::drawPrisoner(sf::RenderWindow &window) {
	sf::Vector2i PrisonAnim(1, Down);
	
	if (!prisonerTexture.loadFromFile("../assets/image_assets/prisoner_images.png")) {
		std::cout << "Error could not load prisoner texture" << std::endl;
		system("pause");
}
	prisonerSprite.setTexture(prisonerTexture);
	
	 prisonerPosition.x = prisonerSprite.getPosition().x;
	 prisonerPosition.y = prisonerSprite.getPosition().y;

	std::string SecondsString = std::to_string(prisonTime);
	sf::Time TimeElapsed = PrisonClock.getElapsedTime(); // setting the time to the hud clock, so it can count seconds
	sf::Time seconds = sf::seconds(1); // this is to compare to the time elapsed to get 1 second


	

	if (TimeElapsed >= seconds) { // if the time elapsed is a second, increment the HUDTime and restart the HUDClock 
		prisonTime++;
		PrisonClock.restart();
		//std::cout << "Minutes: " << HUDTimeMinute << ", Seconds: " << HUDTime << std::endl;
		std::cout << prisonTime << std::endl;
	}


	if (prisonTime >= 5) {
		PrisonMove = rand() % 6; // a random number generator between 1 and 8
		prisonTime = 0;
	}

	

		if (PrisonMove == 1) { // Up Facing prisoner
			if (prisonerSprite.getPosition().y > 64) {
				PrisonAnim.y = Up;
				movePrisoner('u', Speed);
				lastPrisonerPosition = Up;
			}
		}
		else if (PrisonMove == 2) { // Down Facing Prisoner
			if (prisonerSprite.getPosition().x > 64) {
				PrisonAnim.y = Left;
				movePrisoner('l', Speed);
				lastPrisonerPosition = Left;
			}
		}
		else if (PrisonMove == 3) { // Left Facing Prisoner
			if (prisonerSprite.getPosition().y < 4416) {
				PrisonAnim.y = Down;
				movePrisoner('d', Speed);
				lastPrisonerPosition = Down;
			}
		}
		else if (PrisonMove == 4) { // Right Facing Prisoner
			if (prisonerSprite.getPosition().x < 2752) {
				PrisonAnim.y = Right;
				movePrisoner('r', Speed);
				lastPrisonerPosition = Right;
			}
		}
		else {
			PrisonAnim.y = Idle;
			movePrisoner('i', Speed);
			lastPrisonerPosition = Idle;
		}


	
	

		PrisonAnim.x++;
		if (PrisonAnim.x * 64 >= prisonerTexture.getSize().x) { // once the sprite reaches the end of the sprite sheet, reset to 0 again
			PrisonAnim.x = 0;
		}

		prisonerSprite.setTextureRect(sf::IntRect(PrisonAnim.x * 64, PrisonAnim.y * 64, 64, 64)); // cropping the image with the position and size of the image 

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

void Prisoner::movePrisoner(char direction, float moveSpeed) {
	if (direction == 'u') {
		prisonerSprite.move(0, -moveSpeed);
	}
	else if (direction == 'd') {
		prisonerSprite.move(0, moveSpeed);
	}
	if (direction == 'l') {
		prisonerSprite.move(-moveSpeed, 0);
	}
	else if (direction == 'r') {
		prisonerSprite.move(moveSpeed, 0);
	}
	else if (direction == 'i') {
		prisonerSprite.move(0, 0);
	}
}