#include <SFML/Graphics.hpp>
#include <SFML\Audio.hpp>
#include <cstdlib>

#include "Menu.h"
#include "SkillMenu.h"
#include "Player.h"
#include "Background.h"
#include "HUD.h"
#include "mapLoader.h"
#include "Furniture.h"
#include "Prisoner.h"
#include "Guard.h"
#include "Collision.hpp"
#include "Box2D\Box2D.h"
#include "b2GLDraw.h"
#include "SkillItems.h"
enum GameState { StartMenu, SkillsMenu, Options, Game };


int GameState = StartMenu;

sf::Vector2i ScreenSize(800, 600);
sf::Vector2f pos(ScreenSize.x / 2, ScreenSize.y / 2); // halving the screen size to set the centre of screen as the movement position

int main()
{
	b2Vec2 noGrav(0.0f, 0.0f);
	b2World world(noGrav);

	float32 timeStep = 1 / 60.0f;      //time passed as (seconds)
	int32 velocityIterations = 8.f;   //correct velocity
	int32 positionIterations = 3.f;   // correct position

	b2GLDraw debugInstance;
	world.SetDebugDraw(&debugInstance);
	uint32 flags = 0;
	flags += b2Draw::e_aabbBit;
	flags += b2Draw::e_centerOfMassBit;
	flags += b2Draw::e_jointBit;
	flags += b2Draw::e_pairBit;
	flags += b2Draw::e_shapeBit;

	debugInstance.SetFlags(flags);



	sf::Vector2i ScreenSize(800, 600);
	
	sf::RenderWindow window(sf::VideoMode(ScreenSize.x, ScreenSize.y), "Prison Escape Game");



	Menu menu(window.getSize().x, window.getSize().y); // creating the start menu
	SkillMenu skillmenu(window.getSize().x, window.getSize().y); // creating the Skill menu
	mapLoader map;
	Background background("../assets/image_assets/Background.png");
	Background background2("../assets/image_assets/Background2.png");
	Background SkillsBackground("../assets/image_assets/SkillsMenuBackground.png");
	HUD hud;

	Furniture furniture;
	SkillItems skillitems;

	Player player;
	Prisoner prisoner;
	Guard guard;

	

	sf::SoundBuffer soundBuffer; // sound buffer
	sf::Music menuMusic; // backgroundMusic

	menuMusic.setVolume(50.0f);
	if (!menuMusic.openFromFile("../assets/music_assets/BlueHighway.ogg")) { // SFML sucks and doesnt support MP3
		std::cout << "Background music not loaded" << std::endl;
		return -1;
	}
	//menuMusic.play(); // play the menu music
	menuMusic.getLoop();
	sf::View view; //setting the view for the scrolling screen
	view.reset(sf::FloatRect(0, 0, ScreenSize.x, ScreenSize.y));
	view.setViewport(sf::FloatRect(0, 0, 1.0f, 1.0f)); // from the left point(start point to width scale), top(start to screen height scale), screen width scale, screen height scale

	
	
	


	view.zoom(1.f); // zooming out - FOR DEBUG
	
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			switch(event.type)
				{
			case sf::Event::KeyPressed:
				if (GameState == StartMenu)
				{
					if (sf::Keyboard::Key::Up == event.key.code) {

						menu.Up();
					}
					if (sf::Keyboard::Key::Down == event.key.code) {

						menu.Down();
					}


					if (sf::Keyboard::Key::Return == event.key.code) {
						switch (menu.GetPressedItem()) {
						case 0: std::cout << "play pressed" << std::endl;
							GameState = SkillsMenu;
							break;
						case 1: std::cout << "options pressed" << std::endl;
							//GameState = OptionsMenu;
							break;
						case 2: std::cout << "exit pressed" << std::endl;
							//GameState = Exit;
							window.close();
							break;
						}
					}
				}
				if (GameState == SkillsMenu)
				{
					if (sf::Keyboard::Key::Up == event.key.code) {
						skillmenu.Up();
					}
					if (sf::Keyboard::Key::Down == event.key.code) {

						skillmenu.Down();
					}
					if (sf::Keyboard::Key::Left == event.key.code) {
						switch (skillmenu.GetPressedItem()) {

						case 0: std::cout << "Strength pressed" << std::endl;
							if (skillmenu.playerStrength > 0) {
								hud.playerStrength--;
								skillmenu.startSkillPoints++;
								skillmenu.playerStrength--;
							}
							break;
						case 1: std::cout << "Stamina pressed" << std::endl;
							if (skillmenu.playerStamina > 0) {
								hud.playerStamina--;
								skillmenu.startSkillPoints++;
								skillmenu.playerStamina--;
							}
							break;
						case 2: std::cout << "Endurance pressed" << std::endl;
							if (skillmenu.playerArmour > 0) {
								hud.playerArmour--;
								skillmenu.startSkillPoints++;
								skillmenu.playerArmour--;
							}
							break;
						case 3: std::cout << "Charisma pressed" << std::endl;
							if (skillmenu.playerCharisma > 0) {
								hud.playerCharisma--;
								skillmenu.startSkillPoints++;
								skillmenu.playerCharisma--;
							}
							break;
						case 4: std::cout << "Knowledge pressed" << std::endl;
							if (skillmenu.playerKnowledge > 0) {
								hud.playerKnowledge--;
								skillmenu.startSkillPoints++;
								skillmenu.playerKnowledge--;
							}
							break;

						}
					}
					if (sf::Keyboard::Key::Right == event.key.code) {
						switch (skillmenu.GetPressedItem()) {

						case 0: std::cout << "Strength pressed" << std::endl;
							if (skillmenu.startSkillPoints != 0) {
								hud.playerStrength++;
								skillmenu.startSkillPoints--;
								skillmenu.playerStrength++;
							}
							break;
						case 1: std::cout << "Stamina pressed" << std::endl;
							if (skillmenu.startSkillPoints != 0) {
								hud.playerStamina++;
								skillmenu.startSkillPoints--;
								skillmenu.playerStamina++;
							}
							break;
						case 2: std::cout << "Endurance pressed" << std::endl;
							if (skillmenu.startSkillPoints != 0) {
								hud.playerArmour++;
								skillmenu.startSkillPoints--;
								skillmenu.playerArmour++;
							}
							break;
						case 3: std::cout << "Charisma pressed" << std::endl;
							if (skillmenu.startSkillPoints != 0) {
								hud.playerCharisma++;
								skillmenu.startSkillPoints--;
								skillmenu.playerCharisma++;
							}
							break;
						case 4: std::cout << "Knowledge pressed" << std::endl;
							if (skillmenu.startSkillPoints != 0) {
								hud.playerKnowledge++;
								skillmenu.startSkillPoints--;
								skillmenu.playerKnowledge++;
							}
							break;
							
						}
					}

					if (sf::Keyboard::Return == event.key.code) {
						switch (skillmenu.GetPressedItem()) {
					
						case 5: std::cout << "exit skill pressed" << std::endl;
							//GameState = Exit;
							skillmenu.Up();
							GameState = StartMenu;
							break;

						case 6: std::cout << "Game pressed" << std::endl;
							//GameState = Exit;
							if (skillmenu.startSkillPoints == 0) {
								GameState = Game;
							}
							break;
						}
					}

				}
			
				break;
				}
			
				
			
			if (event.type == sf::Event::Closed)
				window.close();
		}
		
		//std::cout << clock.getElapsedTime().asMicroseconds() << std::endl;
		
		if (Collision::PixelPerfectTest(player.characterSprite, prisoner.prisonerSprite)) {
			std::cout << "Collision" << std::endl;
			
			//	prisoner.prisonerHealth -= (1 + hud.playerStrength);
				std::cout << "attack: Damage = " + (1 + hud.playerStrength) << std::endl;
				//prisonerAngry;
		}


		if (Collision::PixelPerfectTest(guard.guardSprite, player.characterSprite)) {
			std::cout << "Collision" << std::endl;
			
			//	guard.guardHealth -= (1 + hud.playerStrength);
				std::cout << "attack: Damage = " + (1 + hud.playerStrength) << std::endl;
			}
		

		if (Collision::PixelPerfectTest(guard.guardSprite, prisoner.prisonerSprite)) {
			std::cout << "Collision" << std::endl;
		}

		if (player.characterSprite.getPosition().x + 16 > ScreenSize.x / 2 + 16) {  // if the the player sprite with added amount gets beyond half the screen size, stop moving the player
			pos.x = player.characterSprite.getPosition().x + 16;
		}
		else {
			pos.x = ScreenSize.x / 2;
		}
		if (player.characterSprite.getPosition().y + 16 > ScreenSize.y / 2 + 16) {// if the the player sprite with added amount gets beyond half the screen size, stop moving the player
			pos.y = player.characterSprite.getPosition().y + 16;
		}
		else {
			pos.y = ScreenSize.y / 2;
		}

		window.clear(sf::Color(0, 240, 255));
		world.Step(timeStep, velocityIterations, positionIterations); /*!<  steps the world physics - like a game loop for the box2d world */
		
		if (GameState == SkillsMenu) {
			SkillsBackground.drawBackground(window);
			skillmenu.drawBars(window);
			skillmenu.draw(window);
		}

		view.setCenter(pos); 
		
		//setting the position of the bars in the HUD file
	
		window.setView(view); // setting the view
		//clearing screen
	
		//drawing 
		if (GameState == Game)
		{
			


			menuMusic.pause(); // pause that funky music
		//	background.drawBackground(window);
			map.drawMap(window);
			furniture.Doors(window);
			furniture.smallFurniture(window);
			furniture.mediumFurniture(window);
			furniture.largeFurniture(window);
			furniture.WorkShop(window);
			
			skillitems.WeightsBench(window);
			skillitems.ExercBike(window);

			player.drawPlayer(world, view, window);
			
			
			

			prisoner.drawPrisoner(window);

			guard.drawGuard(window);
			
			
			hud.drawHUD(view, window);
			hud.HUDUserInput(view, window);
			

			world.DrawDebugData(); // drawing the debug data


			if (hud.SkilOpen == true) {
				hud.drawSkills(view, window);
			}
			if (hud.MisOpen == true) {
				hud.drawMissions(view, window);
			}
			if (hud.InvOpen == true) {
				hud.drawInventory(view, window);
			}

		

		}

		

		int LightFlicker = rand()% 10;
		for (int x = 1; x < 256; x++) {
			int LightFlicker = rand() % 10; // flickering the light only slightly, by having random number generator
		}
		if (GameState == StartMenu) {
				
				if (LightFlicker == 8) { // if the value is 8, paint the background with the background with no lighting
					background2.drawBackground(window);
				}
				else {
					background.drawBackground(window); // if not paint the light background
				}
			
		
			menu.draw(window);
			
		}

		//displaying drawn stuff
		window.display();
	}

	return EXIT_SUCCESS;
}


// https://www.youtube.com/watch?v=ghgd-R1gRmc - 22:51 - 24/11/2017
// https://www.sfml-dev.org/tutorials/2.4/graphics-view.php - look at this for scrolling view screen
//https://www.youtube.com/watch?v=ma5QWDYsmBg - Spritesheet
//https://www.youtube.com/watch?v=SYrzeVEjRE0 - clock sprite movement

// http://freemusicarchive.org/curator/video - sound assets placeholder