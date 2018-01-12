#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>
#include <sstream>




class HUD
{
public:
	sf::CircleShape PlayerIcon;

	sf::RectangleShape clockOuterBox, clockDigital, date;

	sf::RectangleShape PlayerBox, noHealth, health, noXP, XP, prisonPound;

	

	sf::RectangleShape box, box1, box2;

	sf::RectangleShape StrengthBar, StaminaBar, ArmourBar, CharismaBar, KnowledgeBar;

	sf::RectangleShape Strength, Stamina, Armour, Charisma, Knowledge;

	sf::RectangleShape MissionsBox, SkillsBox, InventoryBox, characterBox, CashBox;

	sf::Clock HUDClock;

	sf::Texture playerTexture, halfHealthPlayer, lowHealthPlayer, poundTexture;
	sf::Texture Skills, Inventory, Missions;

	sf::Font font, HUDFont, HUDFont2;


	bool MisOpen = false;
	bool SkilOpen = false;
	bool InvOpen = false;


	float healthBar = 210;
	float XPcount = 0;
	float HUDopacity = 150;

	float maxXP = 210; //create a system where the maxXP costs more each level of the players health
	int playerLevel = 1; // (maxXP * playerLevel) + or * someValue so that each level is harder than the last

	
	int MisOpenCount = 0; // way of knowing if the player has hit the key twice
	int InvOpenCount = 0; // way of knowing if the player has hit the key twice
	int SkilOpenCount = 0; // way of knowing if the player has hit the key twice

	int HUDTime = 0; // this will be the time for the screen
	int HUDTimeMinute = 0; // hudtime minutes
	int day = 0; // the day number
	
	int prisonMoney = 0; // the cash you start with

	

	float night = 100; // box hue


	int playerStrength; // the stat number that will affect the skills bar
	int playerStamina;
	int playerArmour;
	int playerCharisma;
	int playerKnowledge;
	
	HUD();

	void drawMissions(sf::View &view, sf::RenderWindow &window);
	void drawSkills(sf::View &view, sf::RenderWindow &window);
	void drawInventory(sf::View &view, sf::RenderWindow &window);
	void drawHUD(sf::View &view, sf::RenderWindow &window);
	void HUDUserInput(sf::View &view, sf::RenderWindow &window);


	

	
};
