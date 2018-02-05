#include <SFML/Graphics.hpp>
#include <SFML\Audio.hpp>
#include <cstdlib>

#include "Background.h"
#include "HUD.h"
#include "Menu.h"
#include "SkillMenu.h"

#include "SkillItems.h"
#include "OptionsMenu.h"
#include "Instructions.h"

#include "Player.h"
#include "Prisoner.h"
#include "Guard.h"
#include "Warden.h"


#include "mapLoader.h"
#include "Furniture.h"
#include "prisonWalls.h"

#include "furnitureInv.h"

#include "Collision.h"
#include "prisonerDialogue.h"
#include "guardDialogue.h"

/*TODO - 
Physics: Particle emitter for shower water, Collision for wall and floor vectors
Characters: 2 Nurse Characters, make multiple instances of prisoner and guards
HUDItems: Finish the Instructions Menu, Crafting menu needs to be implemented, MouseHander for HUDItems, including start menu
Objects: Make Skill Item furniture have collision and make them increment skill on use
AI: Path Finding Algorithm A* - Use on all characters, use the given states in the class to change their behavior
*/


enum GameState { StartMenu, SkillsMenu, Options, Game, InstructionsMenu };
enum dialogueState { prisonerTalk, guardTalk, prisonerMissions, guardMissions, snitching, prisonerTrade, dialogueMenu, noState };

int GameState = StartMenu;

float musicVolume;
bool prisonAction = false;
bool guardAction = false;

sf::Vector2i ScreenSize(800, 600);
sf::Vector2f pos(ScreenSize.x / 2, ScreenSize.y / 2); // halving the screen size to set the centre of screen as the movement position

int main()
{
	int dialogueState = noState; // setting it to no state, as not interacted with prisoner or guard yet
	sf::Vector2f playerStartPos(100.0f, 100.f);

	sf::Vector2i ScreenSize(800, 600);
	sf::Vector2f direction;
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
	


	Player player(sf::Vector2f(32,32), sf::Vector2f(150, 150));
	Prisoner prisoner(sf::Vector2f(32, 32), sf::Vector2f(200, 150));
	Guard guard(sf::Vector2f(32, 32), sf::Vector2f(150, 250));
	Warden warden(sf::Vector2f(32, 32), sf::Vector2f((40*64), (20*64)));

	prisonWalls walls;
	
	furnitureInv furninv;

	


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

	prisonerDialogue prisonD;
	guardDialogue guardD;


	view.zoom(1.0f); // zooming out - FOR DEBUG

	while (window.isOpen())
	{
	
		sf::Event event;
		while (window.pollEvent(event))
		{

			switch(event.type)
				{
			case sf::Event::KeyPressed:
				if (GameState == Game) {
					if (player.getCollision().collision(prisoner.getCollision(), 1.0f, direction)) { // player collision with prisoner
						player.onCollision(direction);
						prisoner.onCollision(direction);
						if (sf::Keyboard::Key::E == event.key.code) {
							prisonAction = true; // boolean to draw dialogue menu
							dialogueState = dialogueMenu; // setting the state for the dialogue
							prisonerState::prisonerStop; // stopping the prisoner from moving
						}
					}
					else {
						prisonerState::IDLE; // making the prisoner go back to idle after interaction
					}
					if (player.getCollision().collision(guard.getCollision(), 1.0f, direction)) { // player collision with guard
						player.onCollision(direction);
						if (sf::Keyboard::Key::E == event.key.code) {
							guardAction = true; // boolean to draw dialogue menu 
							dialogueState = dialogueMenu;// setting the state for the dialogue
							guardState::guardStop; // stopping the guard from moving
						}
					}
					else {
						guardState::guardIDLE;// making the guard go back to idle after interaction
					}

					if (player.getCollision().collision(warden.getCollision(), 1.0f, direction)) { // player collision with guard
						player.onCollision(direction);
						warden.onCollision(direction);
					}

					if (prisoner.getCollision().collision(guard.getCollision(), 1.0f, direction)) { // player collision with guard
						prisoner.onCollision(direction);
						guard.onCollision(direction);
					}

					if (player.getCollision().collision(walls.getCollision(), 0.0f, direction)) { // player collision with walls
						player.onCollision(direction);
						//walls.onCollision(direction);
					}

				}


			

				if (prisonAction == true) {
					if (sf::Keyboard::Key::Up == event.key.code) {
						prisonD.Up();
					}
					if (sf::Keyboard::Key::Down == event.key.code) {
						prisonD.Down();
					}
					if (sf::Keyboard::Key::Return == event.key.code) {
						switch (prisonD.GetPressedItem()) {
						case 0: std::cout << "Talk" << std::endl;
							dialogueState = prisonerTalk; // setting the state to prisoner talk
							
							break;
						case 1: std::cout << "Trade" << std::endl;
							dialogueState = prisonerTrade;// setting the state to prisoner trade
							break;
						case 2: std::cout << "Missions" << std::endl;
							dialogueState = prisonerMissions;// setting the state to prisoner missions
							break;
						
						}
					}
				}
				if (guardAction == true) {
					if (sf::Keyboard::Key::Up == event.key.code) {
						guardD.Up();
					}
					if (sf::Keyboard::Key::Down == event.key.code) {
						guardD.Down();
					}
					if (sf::Keyboard::Key::Return == event.key.code) {
						switch (guardD.GetPressedItem()) {
						case 0: std::cout << "Talk" << std::endl;
							dialogueState = guardTalk; // setting the state to guard talk
							break;
						case 1: std::cout << "Snitch" << std::endl;
							dialogueState = snitching; // setting the state to snitching
							break;
						case 2: std::cout << "Missions" << std::endl;
							dialogueState = guardMissions; //setting the state to guard missions
							break;
						
						}
					}
				}


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

			player.playerKeyboardMovement(view, window);
			
		//	furninv.drawFootLocker(view, window);

		


			prisoner.drawPrisoner(window);
			warden.drawWarden(window);
			guard.drawGuard(window);
			
			
			hud.drawHUD(view, window);
			hud.HUDUserInput(view, window);
			hud.MouseInput(window);

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

			//BOTH GUARD AND PRISONER_______________________________
			if (dialogueState == dialogueMenu) {
				if (prisonAction == true) {
					guardAction = false;
					prisonD.drawDialogueBox(view, window);
					prisonD.draw(view, window);
					if (sf::Keyboard::Key::X == event.key.code) {
						dialogueState = noState;
						
					}
				}
			
				 if (guardAction == true) {
					prisonAction = false;
					guardD.drawDialogueBox(view, window);
					guardD.draw(view, window);
					if (sf::Keyboard::Key::X == event.key.code) {
						dialogueState = noState;
					}
				 }
				
			}
			//PRISONER_______________________________________________
			if (dialogueState == prisonerTalk) {
				prisonD.drawDialogueBox(view, window);
				prisonD.Talk(view, window);
				guardD.prisonInfo = 1;
				if (sf::Keyboard::Key::X == event.key.code) {
					dialogueState = noState;
				}
			}
			if (dialogueState == prisonerTrade) {
				prisonD.drawDialogueBox(view, window);
				prisonD.Trade(view, window);
				if (sf::Keyboard::Key::X == event.key.code) {
					dialogueState = noState;
				}
			}
			if (dialogueState == prisonerMissions) {
				prisonD.drawDialogueBox(view, window);
				prisonD.Mission(view, window);
				if (sf::Keyboard::Key::X == event.key.code) {
					dialogueState = noState;
				}
			}
			//GUARD___________________________________________________
			if (dialogueState == guardTalk) {
				guardD.drawDialogueBox(view, window);
				guardD.Talk(view, window);
				if (sf::Keyboard::Key::X == event.key.code) {
					dialogueState = noState;
				}
			}
			if (dialogueState == snitching) {
				guardD.drawDialogueBox(view, window);
				guardD.Snitch(view, window);
				if (sf::Keyboard::Key::X == event.key.code) {
					dialogueState = noState;
				}
			}
			if (dialogueState == guardMissions) {
				guardD.drawDialogueBox(view, window);
				guardD.Mission(view, window);
				if (sf::Keyboard::Key::X == event.key.code) {
					dialogueState = noState;
				}
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