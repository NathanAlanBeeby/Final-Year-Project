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
#include "SkillItems.h"
#include "OptionsMenu.h"
#include "Instructions.h"
#include "prisonWalls.h"
enum GameState { StartMenu, SkillsMenu, Options, Game, InstructionsMenu };


int GameState = StartMenu;

float musicVolume;


sf::Vector2i ScreenSize(800, 600);
sf::Vector2f pos(ScreenSize.x / 2, ScreenSize.y / 2); // halving the screen size to set the centre of screen as the movement position

int main()
{

	sf::Vector2f playerStartPos(100.0f, 100.f);

	sf::Vector2i ScreenSize(800, 600);
	
	sf::RenderWindow window(sf::VideoMode(ScreenSize.x, ScreenSize.y), "Prison Escape Game");



	Menu menu(window.getSize().x, window.getSize().y); // creating the start menu
	OptionsMenu options(window.getSize().x, window.getSize().y); // crating the options menu 
	Instructions instructions(window.getSize().x, window.getSize().y); 

	SkillMenu skillmenu(window.getSize().x, window.getSize().y); // creating the Skill menu
	mapLoader map;
	Background background("../assets/image_assets/Background.png");
	Background background2("../assets/image_assets/Background2.png");
	Background SkillsBackground("../assets/image_assets/SkillsMenuBackground.png");
	Background OptionsBackground("../assets/image_assets/OptionsBackground.png");
	Background InstructionsBackground("../assets/image_assets/InstructionsBackground.png");
	HUD hud;

	Furniture furniture;
	SkillItems skillitems;
	Player player;
	Prisoner prisoner;
	Guard guard;
	prisonWalls walls;

	

	sf::SoundBuffer soundBuffer; // sound buffer
	sf::Music menuMusic; // backgroundMusic
	


	if (!menuMusic.openFromFile("../assets/music_assets/BlueHighway.ogg")) { // SFML sucks and doesnt support MP3
		std::cout << "Background music not loaded" << std::endl;
		return -1;
	}
//	menuMusic.play(); // play the menu music
	menuMusic.getLoop();
	sf::View view; //setting the view for the scrolling screen
	view.reset(sf::FloatRect(0, 0, ScreenSize.x, ScreenSize.y));
	view.setViewport(sf::FloatRect(0, 0, 1.0f, 1.0f)); // from the left point(start point to width scale), top(start to screen height scale), screen width scale, screen height scale



	view.zoom(1.0f); // zooming out - FOR DEBUG
	
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
							GameState = Options;
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
			
				if (GameState == Options) {
					musicVolume = options.Music;
					menuMusic.setVolume(musicVolume);
					if (sf::Keyboard::Key::Up == event.key.code) {
						options.Up();
					}
					if (sf::Keyboard::Key::Down == event.key.code) {
						options.Down();
					}

					if (sf::Keyboard::Key::Left == event.key.code) {
						switch (options.GetPressedItem()) {

						case 0: std::cout << "Sound pressed" << std::endl;
							if (options.Sound != 0) {
								options.Sound--;
							}
							break;
						case 1: std::cout << "Music pressed" << std::endl;
							if (options.Music != 0) {
								
								options.Music--;
							}
							break;
						}
					}

						if (sf::Keyboard::Key::Right == event.key.code) {
							switch (options.GetPressedItem()) {

							case 0: std::cout << "Sound pressed" << std::endl;
								if (options.Sound <= 99) {
									options.Sound++;

								
								}
								break;
							case 1: std::cout << "Music pressed" << std::endl;
								if (options.Music <= 99) {
									options.Music++;
									
								}
								break;
							}
						}
							if (sf::Keyboard::Key::Return == event.key.code) {
								switch (options.GetPressedItem()) {
								case 2: std::cout << "Instructions" << std::endl;
									GameState = InstructionsMenu;
									break;
								case 3: std::cout << "Back" << std::endl;
									GameState = StartMenu;
									options.Up();
									break;
								
								}
							}
						}
				if (GameState == InstructionsMenu) {
					if (sf::Keyboard::Key::Up == event.key.code) {
						instructions.Up();
					}
					if (sf::Keyboard::Key::Down == event.key.code) {
						instructions.Down();
					}
					if (sf::Keyboard::Key::Return == event.key.code) {
						switch (instructions.GetPressedItem()) {
						case 0: std::cout << "Keys" << std::endl;
							
							break;
						case 1: std::cout << "Crafting" << std::endl;
						
						
							break;
						case 2: std::cout << "Skills" << std::endl;
						
							break;
						case 3: std::cout << "Routine" << std::endl;
						
							break;
						case 4: std::cout << "Back" << std::endl;
							GameState = Options;
							instructions.Up();
							break;
						case 5: std::cout << "Next" << std::endl;

							break;
						}
					}
				}
						
					}
				
				
			
			if (event.type == sf::Event::Closed)
				window.close();
		}
		
		//std::cout << clock.getElapsedTime().asMicroseconds() << std::endl;
		
	

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
		if (GameState == InstructionsMenu) {
			InstructionsBackground.drawBackground(window);
			instructions.draw(window);
		}
		if (GameState == Options) {
			OptionsBackground.drawBackground(window);
			options.draw(window);
			options.drawBars(window);
		}
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
			//std::cout << "Player Movement: X = " << player.CharPosition.x << "; Y = " << player.CharPosition.y << std::endl;
			//std::cout << "Player Position - X: " << player.posX << ", Y:" << player.posY << std::endl;
			//std::cout << "Guard Position - X: " << guard.posX << ", Y:" << guard.posY << std::endl;
			//std::cout << "Prisoner Position - X: " << prisoner.posX << ", Y:" << prisoner.posY << std::endl;

			menuMusic.pause(); // pause that funky music
		//	background.drawBackground(window);
			map.drawMap(window);

			//drawing the walls
			walls.outerWalls(window);
			walls.cellblockInnerWalls(window);
			walls.medicalInnerWalls(window);
			walls.wardenVisitationInnerWalls(window);
			walls.closetAndCafInnerWalls(window);
			walls.yardInnerWalls(window);
			walls.workLaundSecInnerWalls(window);
			walls.solitaryLibraryInnerWalls(window);

			furniture.Doors(window);
			furniture.smallFurniture(window);
			furniture.mediumFurniture(window);
			furniture.largeFurniture(window);
			furniture.WorkShop(window);
			
			skillitems.WeightsBench(window);
			skillitems.ExercBike(window);

			player.drawPlayer(view, window);
			
			
			

			prisoner.drawPrisoner(window);

			guard.drawGuard(window);
			
			
			hud.drawHUD(view, window);
			hud.HUDUserInput(view, window);
			

			if (hud.SkilOpen == true) {
				hud.drawSkills(view, window);
			}
			if (hud.MisOpen == true) {
				hud.drawMissions(view, window);
			}
			if (hud.InvOpen == true) {
				hud.drawInventory(view, window);
			} if (hud.RepOpen == true) {
				hud.drawReputation(view, window);
			}
			if (hud.craftOpen == true) {
				hud.drawCraft(view, window);
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