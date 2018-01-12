#include "HUD.h"

	HUD::HUD() {
	playerStrength = 0;
	playerStamina = 0;
	playerArmour = 0;
	playerCharisma = 0;
	playerKnowledge = 0;
}

	void HUD::drawMissions(sf::View &view, sf::RenderWindow &window) {
	MissionsBox.setSize(sf::Vector2f(250, 400));
	MissionsBox.setFillColor(sf::Color(242, 232, 171, HUDopacity));
	MissionsBox.setOutlineThickness(2);
	MissionsBox.setOutlineColor(sf::Color(0, 0, 0, HUDopacity));
	MissionsBox.setPosition(view.getCenter().x - 125, view.getCenter().y - 130);

	sf::Text MissionsHeader;
	MissionsHeader.setFont(HUDFont);
	MissionsHeader.setFillColor(sf::Color(0, 0, 0, HUDopacity));
	MissionsHeader.setString("Missions");
	MissionsHeader.setCharacterSize(35);
	MissionsHeader.setPosition(MissionsBox.getPosition().x + 50, MissionsBox.getPosition().y + 20);
	window.draw(MissionsBox);
	window.draw(MissionsHeader);
}
	void HUD::drawSkills(sf::View &view, sf::RenderWindow &window) {
	SkillsBox.setSize(sf::Vector2f(250, 370));
	SkillsBox.setFillColor(sf::Color(100, 100, 100, HUDopacity));
	SkillsBox.setOutlineThickness(2);
	SkillsBox.setOutlineColor(sf::Color(0, 0, 0, HUDopacity));
	SkillsBox.setPosition(view.getCenter().x - 390, view.getCenter().y - 130);

	std::string StrengthString = std::to_string(playerStrength); // converting the int to string, so player knows the stats
	std::string StaminaString = std::to_string(playerStamina);
	std::string ArmourString = std::to_string(playerArmour);
	std::string CharismaString = std::to_string(playerCharisma);
	std::string KnowledgeString = std::to_string(playerKnowledge);

	StrengthBar.setSize(sf::Vector2f(200, 20));
	StrengthBar.setFillColor(sf::Color(255, 0, 0, HUDopacity));
	StrengthBar.setOutlineThickness(2);
	StrengthBar.setOutlineColor(sf::Color(0, 0, 0, HUDopacity));

	Strength.setSize(sf::Vector2f((playerStrength * 2), 20));
	Strength.setFillColor(sf::Color(237, 221, 80, HUDopacity));

	StaminaBar.setSize(sf::Vector2f(200, 20));
	StaminaBar.setFillColor(sf::Color(255, 0, 0, HUDopacity));
	StaminaBar.setOutlineThickness(2);
	StaminaBar.setOutlineColor(sf::Color(0, 0, 0, HUDopacity));

	Stamina.setSize(sf::Vector2f((playerStamina * 2), 20));
	Stamina.setFillColor(sf::Color(32, 157, 234, HUDopacity));

	ArmourBar.setSize(sf::Vector2f(200, 20));
	ArmourBar.setFillColor(sf::Color(255, 0, 0, HUDopacity));
	ArmourBar.setOutlineThickness(2);
	ArmourBar.setOutlineColor(sf::Color(0, 0, 0, HUDopacity));

	Armour.setSize(sf::Vector2f((playerArmour * 2), 20));
	Armour.setFillColor(sf::Color(175, 219, 206, HUDopacity));

	CharismaBar.setSize(sf::Vector2f(200, 20));
	CharismaBar.setFillColor(sf::Color(255, 0, 0, HUDopacity));
	CharismaBar.setOutlineThickness(2);
	CharismaBar.setOutlineColor(sf::Color(0, 0, 0, HUDopacity));

	Charisma.setSize(sf::Vector2f((playerCharisma * 2), 20));
	Charisma.setFillColor(sf::Color(155, 71, 216, HUDopacity));

	KnowledgeBar.setSize(sf::Vector2f(200, 20));
	KnowledgeBar.setFillColor(sf::Color(255, 0, 0, HUDopacity));
	KnowledgeBar.setOutlineThickness(2);
	KnowledgeBar.setOutlineColor(sf::Color(0, 0, 0, HUDopacity));

	Knowledge.setSize(sf::Vector2f((playerKnowledge * 2), 20));
	Knowledge.setFillColor(sf::Color(70, 234, 60, HUDopacity));

	sf::Text SkillsText, strengthText, staminaText, armourText, charismaText, knowledgeText;
	SkillsText.setFont(HUDFont);
	SkillsText.setFillColor(sf::Color(255, 255, 255, HUDopacity));
	SkillsText.setString("Skills");
	SkillsText.setCharacterSize(30);

	strengthText.setFont(HUDFont2);
	strengthText.setFillColor(sf::Color(255, 255, 255, HUDopacity));
	strengthText.setString("Strength: " + StrengthString);
	strengthText.setCharacterSize(35);

	staminaText.setFont(HUDFont2);
	staminaText.setFillColor(sf::Color(255, 255, 255, HUDopacity));
	staminaText.setString("Stamina: " + StaminaString);
	staminaText.setCharacterSize(35);

	armourText.setFont(HUDFont2);
	armourText.setFillColor(sf::Color(255, 255, 255, HUDopacity));
	armourText.setString("Endurance: " + ArmourString);
	armourText.setCharacterSize(35);

	charismaText.setFont(HUDFont2);
	charismaText.setFillColor(sf::Color(255, 255, 255, HUDopacity));
	charismaText.setString("Charisma: " + CharismaString);
	charismaText.setCharacterSize(35);

	knowledgeText.setFont(HUDFont2);
	knowledgeText.setString("Knowledge: " + KnowledgeString);
	knowledgeText.setCharacterSize(35);



	SkillsText.setPosition(SkillsBox.getPosition().x + 75, SkillsBox.getPosition().y + 10);
	strengthText.setPosition(SkillsBox.getPosition().x + 20, SkillsBox.getPosition().y + 40); // setting the position relative to the skillbox
	staminaText.setPosition(SkillsBox.getPosition().x + 20, SkillsBox.getPosition().y + 100);
	armourText.setPosition(SkillsBox.getPosition().x + 20, SkillsBox.getPosition().y + 160);
	charismaText.setPosition(SkillsBox.getPosition().x + 20, SkillsBox.getPosition().y + 220);
	knowledgeText.setPosition(SkillsBox.getPosition().x + 20, SkillsBox.getPosition().y + 280);

	StrengthBar.setPosition(SkillsBox.getPosition().x + 20, SkillsBox.getPosition().y + 85); // these are the empty stat bars
	StaminaBar.setPosition(SkillsBox.getPosition().x + 20, SkillsBox.getPosition().y + 145);
	ArmourBar.setPosition(SkillsBox.getPosition().x + 20, SkillsBox.getPosition().y + 205);
	CharismaBar.setPosition(SkillsBox.getPosition().x + 20, SkillsBox.getPosition().y + 265);
	KnowledgeBar.setPosition(SkillsBox.getPosition().x + 20, SkillsBox.getPosition().y + 325);

	Strength.setPosition(StrengthBar.getPosition().x, StrengthBar.getPosition().y); // setting the positions to the respective bars
	Stamina.setPosition(StaminaBar.getPosition().x, StaminaBar.getPosition().y);
	Armour.setPosition(ArmourBar.getPosition().x, ArmourBar.getPosition().y);
	Charisma.setPosition(CharismaBar.getPosition().x, CharismaBar.getPosition().y);
	Knowledge.setPosition(KnowledgeBar.getPosition().x, KnowledgeBar.getPosition().y);

	window.draw(SkillsBox);
	window.draw(SkillsText);
	window.draw(strengthText);
	window.draw(staminaText);
	window.draw(armourText);
	window.draw(charismaText);
	window.draw(knowledgeText);

	window.draw(StrengthBar);
	window.draw(StaminaBar);
	window.draw(ArmourBar);
	window.draw(CharismaBar);
	window.draw(KnowledgeBar);

	window.draw(Strength);
	window.draw(Stamina);
	window.draw(Armour);
	window.draw(Charisma);
	window.draw(Knowledge);


}
	void HUD::drawInventory(sf::View &view, sf::RenderWindow &window) {
	InventoryBox.setSize(sf::Vector2f(250, 420));
	InventoryBox.setFillColor(sf::Color(55, 55, 55, HUDopacity));
	InventoryBox.setOutlineThickness(2);
	InventoryBox.setOutlineColor(sf::Color(0, 0, 0, HUDopacity));
	InventoryBox.setPosition(view.getCenter().x + 140, view.getCenter().y - 190);

	characterBox.setSize(sf::Vector2f(150, 195));
	characterBox.setFillColor(sf::Color(255, 255, 255, HUDopacity));
	characterBox.setOutlineThickness(1);
	characterBox.setOutlineColor(sf::Color(0, 0, 0, HUDopacity));
	characterBox.setPosition(InventoryBox.getPosition().x + 50, InventoryBox.getPosition().y + 70);


	sf::Text InventoryText;
	InventoryText.setFont(HUDFont);
	InventoryText.setFillColor(sf::Color(255, 255, 255, HUDopacity));
	InventoryText.setString("Inventory");
	InventoryText.setCharacterSize(30);
	InventoryText.setPosition(InventoryBox.getPosition().x + 50, InventoryBox.getPosition().y + 10);

	sf::RectangleShape InvSlot1, InvSlot2, InvSlot3, InvSlot4, InvSlot5, InvSlot6, InvSlot7, InvSlot8;
	InvSlot1.setSize(sf::Vector2f(40, 45));
	InvSlot1.setOutlineThickness(1);
	InvSlot1.setOutlineColor(sf::Color(0, 0, 0, HUDopacity));
	InvSlot1.setPosition(InventoryBox.getPosition().x + 5, InventoryBox.getPosition().y + 70);

	InvSlot2.setSize(sf::Vector2f(40, 45));
	InvSlot2.setOutlineThickness(1);
	InvSlot2.setOutlineColor(sf::Color(0, 0, 0, HUDopacity));
	InvSlot2.setPosition(InvSlot1.getPosition().x, InvSlot1.getPosition().y + 50);

	InvSlot3.setSize(sf::Vector2f(40, 45));
	InvSlot3.setOutlineThickness(1);
	InvSlot3.setOutlineColor(sf::Color(0, 0, 0, HUDopacity));
	InvSlot3.setPosition(InvSlot2.getPosition().x, InvSlot2.getPosition().y + 50);

	InvSlot4.setSize(sf::Vector2f(40, 45));
	InvSlot4.setOutlineThickness(1);
	InvSlot4.setOutlineColor(sf::Color(0, 0, 0, HUDopacity));
	InvSlot4.setPosition(InvSlot3.getPosition().x, InvSlot3.getPosition().y + 50);

	InvSlot5.setSize(sf::Vector2f(40, 45));
	InvSlot5.setOutlineThickness(1);
	InvSlot5.setOutlineColor(sf::Color(0, 0, 0, HUDopacity));
	InvSlot5.setPosition(InventoryBox.getPosition().x + 205, InventoryBox.getPosition().y + 70);

	InvSlot6.setSize(sf::Vector2f(40, 45));
	InvSlot6.setOutlineThickness(1);
	InvSlot6.setOutlineColor(sf::Color(0, 0, 0, HUDopacity));
	InvSlot6.setPosition(InvSlot5.getPosition().x, InvSlot5.getPosition().y + 50);

	InvSlot7.setSize(sf::Vector2f(40, 45));
	InvSlot7.setOutlineThickness(1);
	InvSlot7.setOutlineColor(sf::Color(0, 0, 0, HUDopacity));
	InvSlot7.setPosition(InvSlot6.getPosition().x, InvSlot6.getPosition().y + 50);

	InvSlot8.setSize(sf::Vector2f(40, 45));
	InvSlot8.setOutlineThickness(1);
	InvSlot8.setOutlineColor(sf::Color(0, 0, 0, HUDopacity));
	InvSlot8.setPosition(InvSlot7.getPosition().x, InvSlot7.getPosition().y + 50);

	window.draw(InventoryBox);
	window.draw(characterBox);

	window.draw(InvSlot1);
	window.draw(InvSlot2);
	window.draw(InvSlot3);
	window.draw(InvSlot4);
	window.draw(InvSlot5);
	window.draw(InvSlot6);
	window.draw(InvSlot7);
	window.draw(InvSlot8);
	window.draw(InventoryText);
}

	void HUD::HUDUserInput(sf::View &view, sf::RenderWindow &window) {

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) { //skills
			if (MisOpen == false && InvOpen == false) {
				SkilOpenCount++; // incrementing to know if the player has hit the key a second time	

				if ((SkilOpen = true) && SkilOpenCount >= 2) { // if the misOpenCount is 2, return the value back to 0, and turn the missions open screen to false, to stop drawing
					std::cout << "skills Closed" << std::endl;
					SkilOpenCount = 0;
					SkilOpen = false; // shutting the Missions screen down
				}
				else {
					std::cout << "skills Open" << std::endl;
					SkilOpen = true; // opening missions screen, drawing it to screen
				}
			}
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::M)) { //missions
			if (SkilOpen == false && InvOpen == false) {
				MisOpenCount++; // incrementing to know if the player has hit the key a second time	

				if ((MisOpen = true) && MisOpenCount >= 2) { // if the misOpenCount is 2, return the value back to 0, and turn the missions open screen to false, to stop drawing
					std::cout << "Missions Closed" << std::endl;
					MisOpenCount = 0;
					MisOpen = false; // shutting the Missions screen down
				}
				else {
					std::cout << "Missions Open" << std::endl;
					MisOpen = true; // opening missions screen, drawing it to screen
				}
			}
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::I)) { // inventory
			if (SkilOpen == false && MisOpen == false) {
				InvOpenCount++; // incrementing to know if the player has hit the key a second time	

				if ((InvOpen = true) && InvOpenCount >= 2) { // if the misOpenCount is 2, return the value back to 0, and turn the missions open screen to false, to stop drawing
					std::cout << "Inventory Closed" << std::endl;
					InvOpenCount = 0;
					InvOpen = false; // shutting the Missions screen down
				}
				else {
					std::cout << "Inventory Open" << std::endl;
					InvOpen = true; // opening missions screen, drawing it to screen
				}
			}

		}

		/*if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
			if (healthBar != 0) {
				healthBar--;
				XPcount += 10;
			}
		}*/


	if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) { // left mouse button
		sf::Vector2i mousePos = ::sf::Mouse::getPosition(window); // getting the position of the mouse relative to the window


		if (mousePos.y >= box.getPosition().y && mousePos.y <= box.getPosition().y + 50) { // if the y position is between the HUD button

			if (mousePos.x >= box.getPosition().x && mousePos.x <= box.getPosition().x + 50) { // if the x position is on the first HUD button
				if (SkilOpen == false && InvOpen == false) {
					MisOpenCount++; // incrementing to know if the player has hit the key a second time	

					if ((MisOpen = true) && MisOpenCount >= 2) { // if the misOpenCount is 2, return the value back to 0, and turn the missions open screen to false, to stop drawing
						std::cout << "Missions Closed" << std::endl;
						MisOpenCount = 0;
						MisOpen = false; // shutting the Missions screen down
					}
					else {
						std::cout << "Missions Open" << std::endl;
						MisOpen = true; // opening missions screen, drawing it to screen
					}
				}

				//drawMissions(view, window);
			}

			if (mousePos.x >= box1.getPosition().x && mousePos.x <= box1.getPosition().x + 50) { // if the x position is on the first HUD button
				if (MisOpen == false && InvOpen == false) {
					SkilOpenCount++; // incrementing to know if the player has hit the key a second time	

					if ((SkilOpen = true) && SkilOpenCount >= 2) { // if the misOpenCount is 2, return the value back to 0, and turn the missions open screen to false, to stop drawing
						std::cout << "skills Closed" << std::endl;
						SkilOpenCount = 0;
						SkilOpen = false; // shutting the Missions screen down
					}
					else {
						std::cout << "skills Open" << std::endl;
						SkilOpen = true; // opening missions screen, drawing it to screen
					}
				}
				//drawSkills(view, window);
			}

			if (mousePos.x >= box2.getPosition().x && mousePos.x <= box2.getPosition().x + 50) { // if the x position is on the first HUD button
				if (SkilOpen == false && MisOpen == false) {
					InvOpenCount++; // incrementing to know if the player has hit the key a second time	

					if ((InvOpen = true) && InvOpenCount >= 2) { // if the misOpenCount is 2, return the value back to 0, and turn the missions open screen to false, to stop drawing
						std::cout << "Inventory Closed" << std::endl;
						InvOpenCount = 0;
						InvOpen = false; // shutting the Missions screen down
					}
					else {
						std::cout << "Inventory Open" << std::endl;
						InvOpen = true; // opening missions screen, drawing it to screen
					}
				}
				//drawInventory(view, window);
			}
		}
	}

}

void HUD::drawHUD(sf::View &view, sf::RenderWindow &window) {
	if (XPcount >= maxXP) {
		XPcount = 0;
		playerLevel++; // incrementing the player level if the XP count is more than the max required XP
		healthBar += 20; // increasing the health of the player slightly, unless they have full health
		std::cout << playerLevel << std::endl;
	}

	if (healthBar >= 210) { // if the health is more than the maximum, keep it at the max HP(cant go over max HP)
		healthBar = 210;
	}
	if (playerLevel >= 100) {
		playerLevel = 100; //the maximum level is 100
	}
	if (!playerTexture.loadFromFile("../assets/image_assets/sprite_image.png")) {
		std::cout << "Load fail Error on playerFaceTexture" << std::endl;
		system("pause");

	}
	if (!Skills.loadFromFile("../assets/image_assets/Skills.png")) {
		std::cout << "Load fail Error on playerFaceTexture" << std::endl;
		system("pause");

	}
	if (!Inventory.loadFromFile("../assets/image_assets/Inventory.png")) {
		std::cout << "Load fail Error on playerFaceTexture" << std::endl;
		system("pause");

	}
	if (!Missions.loadFromFile("../assets/image_assets/Missions.png")) {
		std::cout << "Load fail Error on playerFaceTexture" << std::endl;
		system("pause");

	}
	if (!halfHealthPlayer.loadFromFile("../assets/image_assets/halfHealth_sprite_image.png")) {
		std::cout << "Load fail Error on playerFaceTexture" << std::endl;
		system("pause");

	}
	if (!lowHealthPlayer.loadFromFile("../assets/image_assets/lowHealth_sprite_image.png")) {
		std::cout << "Load fail Error on playerFaceTexture" << std::endl;
		system("pause");

	}
	if (!HUDFont.loadFromFile("../assets/text_assets/CagedPrisoner.ttf")) {
		std::cout << "Load fail Error on HUDFont" << std::endl;
		system("pause");
	}
	if (!HUDFont2.loadFromFile("../assets/text_assets/FontFile.ttf")) {
		std::cout << "Load fail Error on HUDFont" << std::endl;
		system("pause");
	}

	if (!poundTexture.loadFromFile("../assets/image_assets/PrisonPound.png")) {
		std::cout << "Load fail Error on playerFaceTexture" << std::endl;
		system("pause");

	}


	prisonPound.setSize(sf::Vector2f(50, 50));
	prisonPound.setTexture(&poundTexture);
	prisonPound.setPosition(view.getCenter().x - 25, view.getCenter().y - 280);
	
	std::string moneyString = std::to_string(prisonMoney);
	sf::Text moneyText;
	moneyText.setFont(HUDFont2);
	moneyText.setString(moneyString);
	moneyText.setFillColor(sf::Color(0, 0, 0));
	moneyText.setPosition(view.getCenter().x + 25, view.getCenter().y - 275);

	CashBox.setSize(sf::Vector2f(150, 70));
	CashBox.setFillColor(sf::Color(50, 50, 50, HUDopacity));
	CashBox.setOutlineThickness(2);
	CashBox.setOutlineColor(sf::Color(0, 0, 0, HUDopacity));
	CashBox.setPosition(view.getCenter().x - 35, view.getCenter().y - 290);

	sf::Text HealthText, LevelText, LevelString, XPText, TimerText, dayText, dateText;
	HealthText.setFont(HUDFont);
	HealthText.setString("Health");
	HealthText.setCharacterSize(20);
	HealthText.setPosition(view.getCenter().x - 250, view.getCenter().y - 282);



	XPText.setFont(HUDFont);
	XPText.setString("XP");
	XPText.setCharacterSize(20);
	XPText.setPosition(view.getCenter().x - 220, view.getCenter().y - 252);

	//std::cout << TimeElapsed.asSeconds() << std::endl; 


	std::string MinutesString = std::to_string(HUDTimeMinute);
	std::string SecondsString = std::to_string(HUDTime);
	std::string dayString = std::to_string(day);

	dayText.setFont(HUDFont2);
	dayText.setString("Day : " + dayString);
	dayText.setFillColor(sf::Color(0, 0, 0));
	dayText.setPosition(view.getCenter().x + 235, view.getCenter().y - 285);



	TimerText.setFont(HUDFont2);
	if (HUDTimeMinute <= 9 && HUDTime <= 9) { // if both HUDTime and HUDTimeMinute is less than 9, put a 0 before both 
		TimerText.setString("0" + MinutesString + " : 0" + SecondsString);
	}
	else if (HUDTime <= 9) { // if the HUDTime seconds is less than 9, have a 0 before the number, so it's digital time
		TimerText.setString(MinutesString + " : 0" + SecondsString);
	}
	else if (HUDTimeMinute <= 9) { // ig HUDTimeMinute is less than 9, but a 0 before the minutes
		TimerText.setString("0" + MinutesString + " : " + SecondsString);
	}
	else {
		TimerText.setString(MinutesString + " : " + SecondsString);

	}

	TimerText.setFillColor(sf::Color(0, 0, 0));
	TimerText.setPosition(view.getCenter().x + 235, view.getCenter().y - 245);

	PlayerIcon.setRadius(35);
	if (healthBar >= 110) {
		PlayerIcon.setTexture(&playerTexture);
	}
	else if (healthBar >= 40 && healthBar <= 110) {
		PlayerIcon.setTexture(&halfHealthPlayer);
	}
	else {
		PlayerIcon.setTexture(&lowHealthPlayer);
	}
	PlayerIcon.setTextureRect(sf::IntRect(0, 0, 50, 100));
	PlayerIcon.setOutlineThickness(1);
	PlayerIcon.setOutlineColor(sf::Color(0, 0, 0, HUDopacity));

	PlayerBox.setSize(sf::Vector2f(310, 150));
	PlayerBox.setFillColor(sf::Color(50, 50, 50, HUDopacity));
	PlayerBox.setOutlineThickness(2);
	PlayerBox.setOutlineColor(sf::Color(0, 0, 0, HUDopacity));

	LevelText.setFont(HUDFont2); // level text under the character icon
	LevelText.setString("Level:");
	LevelText.setCharacterSize(35);
	LevelText.setPosition(view.getCenter().x - 370, view.getCenter().y - 220);


	std::string lvlString = std::to_string(playerLevel);
	LevelString.setFont(HUDFont2);
	LevelString.setString(lvlString);
	LevelString.setCharacterSize(35);
	LevelString.setPosition(view.getCenter().x - 370, view.getCenter().y - 190);

	noHealth.setSize(sf::Vector2f(210, 20));
	noHealth.setFillColor(sf::Color(255, 0, 0, HUDopacity));
	noHealth.setOutlineThickness(2);
	noHealth.setOutlineColor(sf::Color(0, 0, 0, HUDopacity));

	health.setSize(sf::Vector2f(healthBar, 20));
	health.setFillColor(sf::Color(0, 255, 0, HUDopacity));

	noXP.setSize(sf::Vector2f(210, 20));
	noXP.setFillColor(sf::Color(100, 100, 100, HUDopacity));
	noXP.setOutlineThickness(2);
	noXP.setOutlineColor(sf::Color(0, 0, 0, HUDopacity));

	XP.setSize(sf::Vector2f(XPcount, 20));
	XP.setFillColor(sf::Color(234, 149, 37, HUDopacity));

	PlayerIcon.setPosition(view.getCenter().x - 380, view.getCenter().y - 280);
	PlayerBox.setPosition(view.getCenter().x - 390, view.getCenter().y - 290);
	noHealth.setPosition(view.getCenter().x - 300, view.getCenter().y - 280);
	health.setPosition(view.getCenter().x - 300, view.getCenter().y - 280);

	noXP.setPosition(view.getCenter().x - 300, view.getCenter().y - 250);
	XP.setPosition(view.getCenter().x - 300, view.getCenter().y - 250);


	box.setSize(sf::Vector2f(50, 50));
	box.setFillColor(sf::Color(255, 255, 255, HUDopacity));
	box.setTexture(&Missions);
	box.setOutlineThickness(1);
	box.setOutlineColor(sf::Color(0, 0, 0, HUDopacity));
	box.setPosition(view.getCenter().x - 160, view.getCenter().y - 220);

	box1.setSize(sf::Vector2f(50, 50));
	box1.setFillColor(sf::Color(255, 255, 255, HUDopacity));
	box1.setTexture(&Skills);
	box1.setOutlineThickness(1);
	box1.setOutlineColor(sf::Color(0, 0, 0, HUDopacity));
	box1.setPosition(view.getCenter().x - 220, view.getCenter().y - 220);

	box2.setSize(sf::Vector2f(50, 50));
	box2.setFillColor(sf::Color(255, 255, 255, HUDopacity));
	box2.setTexture(&Inventory);
	box2.setOutlineThickness(1);
	box2.setOutlineColor(sf::Color(0, 0, 0, HUDopacity));
	box2.setPosition(view.getCenter().x - 280, view.getCenter().y - 220);


	clockOuterBox.setSize(sf::Vector2f(170, 90));
	clockOuterBox.setOutlineThickness(2);
	clockOuterBox.setFillColor(sf::Color(155, 155, 155, HUDopacity));
	clockOuterBox.setOutlineColor(sf::Color(0, 0, 0, HUDopacity));
	clockOuterBox.setPosition(view.getCenter().x + 220, view.getCenter().y - 290);

	date.setSize(sf::Vector2f(150, 30));
	date.setOutlineThickness(2);
	date.setFillColor(sf::Color(50, 50, 50, HUDopacity));
	date.setOutlineColor(sf::Color(0, 0, 0, HUDopacity));
	date.setPosition(view.getCenter().x + 230, view.getCenter().y - 280);

	clockDigital.setSize(sf::Vector2f(150, 30));
	clockDigital.setOutlineThickness(2);
	clockDigital.setFillColor(sf::Color(50, 50, 50, HUDopacity));
	clockDigital.setOutlineColor(sf::Color(0, 0, 0, HUDopacity));
	clockDigital.setPosition(view.getCenter().x + 230, view.getCenter().y - 240);


	sf::Time TimeElapsed = HUDClock.getElapsedTime(); // setting the time to the hud clock, so it can count seconds
	sf::Time seconds = sf::seconds(1); // this is to compare to the time elapsed to get 1 second
	int Minute = 60;



	if (TimeElapsed >= seconds) { // if the time elapsed is a second, increment the HUDTime and restart the HUDClock 
		HUDTime++;
		HUDClock.restart();
		//std::cout << "Minutes: " << HUDTimeMinute << ", Seconds: " << HUDTime << std::endl;

		if (HUDTimeMinute >= 20 && HUDTimeMinute <= 22) { //between the 20th and 22nd minute, increase the nighttime
			if (night < 100) {
				night++;
			}
		}

		if (HUDTimeMinute >= 5 && HUDTimeMinute <= 7) {
			if (night > 0) {
				night--;
			}
		}
	}

	if (HUDTime >= Minute) { // if the HUDTime is more or equal to 60, do this
		HUDTimeMinute++; // increment the hud time minute
		HUDTime = 0; // change the hud time back to 0
		if (HUDTimeMinute >= 24) {// if the hudtime minute is more than 24(like a 24 hour clock)
			day++;
			HUDTimeMinute = 0; // set hudtime back to 0
		}

	}

	sf::RectangleShape daynight(sf::Vector2f(800, 600));
	daynight.setFillColor(sf::Color(0, 0, 255, night));
	daynight.setOrigin(400, 300);

	daynight.setPosition(view.getCenter()); //setting the day night to the view


	window.draw(daynight);

	window.draw(PlayerBox);
	window.draw(box);
	window.draw(box1);
	window.draw(box2);
	window.draw(PlayerIcon);
	window.draw(noHealth);
	window.draw(health);
	window.draw(noXP);
	window.draw(XP);

	window.draw(clockOuterBox);
	window.draw(CashBox);
	window.draw(date);
	window.draw(clockDigital);

	window.draw(HealthText);
	window.draw(XPText);
	window.draw(TimerText);
	window.draw(dayText);
	window.draw(LevelText);
	window.draw(LevelString);
	window.draw(prisonPound);
	window.draw(moneyText);
}