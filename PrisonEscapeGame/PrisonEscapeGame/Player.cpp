#include "Player.h"



	void Player::drawPlayer(sf::View view, sf::RenderWindow &window) {
	if (!spriteTexture.loadFromFile("../assets/image_assets/sprite_images.png"))
			std::cerr << "Error";
	characterSprite.setTexture(spriteTexture);
	
	playerKeyboardMovement(view, window);


	playerPosition.x = characterSprite.getPosition().x;
	playerPosition.y = characterSprite.getPosition().y;
	
	//sf::Vector2f playerSize(64, 64);
	//Collision(playerPosition, playerSize);
}
	//void Player::Collision(sf::Vector2f playerPosition, sf::Vector2f Size) {
		//std::cout << "Player Position - X: " << playerPosition.x << ", Y:" << playerPosition.y << std::endl; // getting the player position and size to get the collision bounds
		//std::cout << "Player Size - X: " << Size.x << ", Y:" << Size.y << std::endl;
	//}

void Player::playerKeyboardMovement(sf::View &view, sf::RenderWindow &window) {

	sf::Vector2i CharAnim(1, Down); // this is a vector with 2 values, the x being the number multiplied by the image width, and the second is the direction

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		if (characterSprite.getPosition().y > 64)
		{
			CharAnim.y = Up;
	
			movePlayer('u', moveSpeed * clock.getElapsedTime().asSeconds());
			lastPosition = Up;
		}
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{
		if (characterSprite.getPosition().y < 4352)
		{
			CharAnim.y = Down;
			
			movePlayer('d', moveSpeed * clock.getElapsedTime().asSeconds());
			lastPosition = Down;
		}
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		if (characterSprite.getPosition().x > 64)
		{
			CharAnim.y = Left;
			
			movePlayer('l', moveSpeed * clock.getElapsedTime().asSeconds());
			lastPosition = Left;
		}
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		if (characterSprite.getPosition().x < 4032)
		{
			CharAnim.y = Right;
			
			movePlayer('r', moveSpeed * clock.getElapsedTime().asSeconds());
			lastPosition = Right;
		}
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
	{
		if (characterSprite.getPosition().y > 0)
		{
			CharAnim.y = Attack;
		
			movePlayer('a', moveSpeed * clock.getElapsedTime().asSeconds());
			lastPosition = Attack;	
		}
	}


	
		CharAnim.x ++; // incrementing the character direction x, to flick through sprite images	
	
	if (CharAnim.x * 64 >= spriteTexture.getSize().x)
	{// if the texture width is greater than 
		CharAnim.x = 0; // when it reaches the edge, go back to 0
	}

	if (!(sf::Keyboard::isKeyPressed(sf::Keyboard::Down) ||
		sf::Keyboard::isKeyPressed(sf::Keyboard::Up) ||
		sf::Keyboard::isKeyPressed(sf::Keyboard::Left) ||
		sf::Keyboard::isKeyPressed(sf::Keyboard::Right) ||
		sf::Keyboard::isKeyPressed(sf::Keyboard::Space)))
	{
		CharAnim = sf::Vector2i(1, lastPosition);
	}

	clock.restart();

	characterSprite.setTextureRect(sf::IntRect(CharAnim.x * 32, CharAnim.y * 32, 32, 32)); // drawing the rectangles position, width and height
	window.draw(characterSprite);

}


void Player::movePlayer(char direction, float moveSpeed) {
		if (direction == 'u') {
			characterSprite.move(0, -moveSpeed);
		}
		else if (direction == 'd') {
			characterSprite.move(0, moveSpeed);
		}
		if (direction == 'l') {
			characterSprite.move(-moveSpeed, 0);
		}
		else if (direction == 'r') {
			characterSprite.move(moveSpeed, 0);
		}
		else if (direction == 'a') {
			characterSprite.move(0, 0);
		}
	}


