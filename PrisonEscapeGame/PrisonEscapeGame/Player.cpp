#include "Player.h"
#include "Prisoner.h"
#include "Guard.h"



void Player::drawPlayer(b2World& world, sf::View view, sf::RenderWindow &window) {
	Collision::CreateTextureAndBitmask(spriteTexture, "../assets/image_assets/sprite_images.png");
	if (!spriteTexture.loadFromFile("../assets/image_assets/sprite_images.png"))
		std::cerr << "Error";
	characterSprite.setTexture(spriteTexture);

	playerKeyboardMovement(view, window);

	
}



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
		if (characterSprite.getPosition().x < 2752)
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

	
	Prisoner prisoner;
	Guard guard;


		CharAnim.x++; // incrementing the character direction x, to flick through sprite images	
	
	


	if (Collision::PixelPerfectTest(characterSprite, prisoner.prisonerSprite)) {
		std::cout << "Collision" << std::endl;
	
		if (CharAnim.y == CharMove::Attack) {
			prisoner.prisonerHealth -= (1 + hud.playerStrength);
			std::cout << "attack: Damage = " + (1 + hud.playerStrength) << std::endl;
			//prisonerAngry;


		}
	}
	if (Collision::PixelPerfectTest(guard.guardSprite, characterSprite)) {
		std::cout << "Collision" << std::endl;
		if (CharAnim.y == CharMove::Attack) {
			guard.guardHealth -= (1 + hud.playerStrength);

			std::cout << "attack: Damage = " + (1 + hud.playerStrength) << std::endl;


		}
	}


	


	clock.restart();

	characterSprite.setTextureRect(sf::IntRect(CharAnim.x * 64, CharAnim.y * 64, 64, 64)); // drawing the rectangles position, width and height
	window.draw(characterSprite);

}

void Player::PlayerMouseInput(sf::RenderWindow &window) {

	if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) { // left mouse button
		sf::Vector2i mousePos = ::sf::Mouse::getPosition(window); // getting the position of the mouse relative to the window

		if (mousePos.y >= hud.box.getPosition().y && mousePos.y <= hud.box.getPosition().y + 50) { // if the y position is between the HUD button
			if (mousePos.x >= hud.box.getPosition().x && mousePos.x <= hud.box.getPosition().x + 50) { // if the x position is on the first HUD button
				std::cout << "button Clicked" << std::endl;
			}

			if (mousePos.x >= hud.box1.getPosition().x && mousePos.x <= hud.box1.getPosition().x + 50) { // if the x position is on the first HUD button
				std::cout << "button 1 Clicked" << std::endl;
			}

			if (mousePos.x >= hud.box2.getPosition().x && mousePos.x <= hud.box2.getPosition().x + 50) { // if the x position is on the first HUD button
				std::cout << "button 2 Clicked" << std::endl;
			}
		}
	}

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