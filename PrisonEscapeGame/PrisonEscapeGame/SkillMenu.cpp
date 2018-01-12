#include "SkillMenu.h"
#include "HUD.h"

HUD hud;

SkillMenu::SkillMenu(float width, float height)
{


	//set the background, draw it out


	if (!font.loadFromFile("../assets/text_assets/FontFile.ttf"))
	{
		// error...
		//	std::cout << "Error loading file" << std::endl;
		system("pause");
	}

	SkillMenuText[0].setFont(font);
	SkillMenuText[0].setCharacterSize(50);
	SkillMenuText[0].setFillColor(sf::Color::Blue);
	SkillMenuText[0].setString("Strength");
	SkillMenuText[0].setPosition(sf::Vector2f(50, height / (skill_item_Number + 8) * 1)); // center item for width, have the amount of string items + 1, so that they're equally spaced out



	SkillMenuText[1].setFont(font);
	SkillMenuText[1].setCharacterSize(50);
	SkillMenuText[1].setFillColor(sf::Color::White);
	SkillMenuText[1].setString("Stamina");
	SkillMenuText[1].setPosition(sf::Vector2f(50, height / (skill_item_Number + 6) * 2.5)); // center item for width, have the amount of string items + 1, so that they're equally spaced out

	SkillMenuText[2].setFont(font);
	SkillMenuText[2].setCharacterSize(50);
	SkillMenuText[2].setFillColor(sf::Color::White);
	SkillMenuText[2].setString("Endurance");
	SkillMenuText[2].setPosition(sf::Vector2f(50, height / (skill_item_Number + 6) * 4)); // center item for width, have the amount of string items + 1, so that they're equally spaced out

	SkillMenuText[3].setFont(font);
	SkillMenuText[3].setCharacterSize(50);
	SkillMenuText[3].setFillColor(sf::Color::White);
	SkillMenuText[3].setString("Charisma");
	SkillMenuText[3].setPosition(sf::Vector2f(50, height / (skill_item_Number + 6) * 5.5)); // center item for width, have the amount of string items + 1, so that they're equally spaced out

	SkillMenuText[4].setFont(font);
	SkillMenuText[4].setCharacterSize(50);
	SkillMenuText[4].setFillColor(sf::Color::White);
	SkillMenuText[4].setString("Knowledge");
	SkillMenuText[4].setPosition(sf::Vector2f(50, height / (skill_item_Number + 6) * 7)); // center item for width, have the amount of string items + 1, so that they're equally spaced out

	SkillMenuText[5].setFont(font);
	SkillMenuText[5].setCharacterSize(50);
	SkillMenuText[5].setFillColor(sf::Color::White);
	SkillMenuText[5].setString("Exit");
	SkillMenuText[5].setPosition(sf::Vector2f(100, height - 90)); // center item for width, have the amount of string items + 1, so that they're equally spaced out

	SkillMenuText[6].setFont(font);
	SkillMenuText[6].setCharacterSize(50);
	SkillMenuText[6].setFillColor(sf::Color::White);
	SkillMenuText[6].setString("Game");
	SkillMenuText[6].setPosition(sf::Vector2f(width - 150,  height - 90)); // center item for width, have the amount of string items + 1, so that they're equally spaced out




	selectedItemIndex = 0;
}


SkillMenu::~SkillMenu()
{
}
void SkillMenu::drawBars(sf::RenderWindow &window) {
	StrBar.setSize(sf::Vector2f(200, 20));
	StrBar.setFillColor(sf::Color(255, 0, 0));
	StrBar.setOutlineThickness(2);
	StrBar.setOutlineColor(sf::Color(0, 0, 0));

	StaBar.setSize(sf::Vector2f(200, 20));
	StaBar.setFillColor(sf::Color(255, 0, 0));
	StaBar.setOutlineThickness(2);
	StaBar.setOutlineColor(sf::Color(0, 0, 0));

	EnduranceBar.setSize(sf::Vector2f(200, 20));
	EnduranceBar.setFillColor(sf::Color(255, 0, 0));
	EnduranceBar.setOutlineThickness(2);
	EnduranceBar.setOutlineColor(sf::Color(0, 0, 0));

	ChaBar.setSize(sf::Vector2f(200, 20));
	ChaBar.setFillColor(sf::Color(255, 0, 0));
	ChaBar.setOutlineThickness(2);
	ChaBar.setOutlineColor(sf::Color(0, 0, 0));

	KnoBar.setSize(sf::Vector2f(200, 20));
	KnoBar.setFillColor(sf::Color(255, 0, 0));
	KnoBar.setOutlineThickness(2);
	KnoBar.setOutlineColor(sf::Color(0, 0, 0));




	Str.setSize(sf::Vector2f((playerStrength * 2), 20));
	Str.setFillColor(sf::Color(237, 221, 80));

	Sta.setSize(sf::Vector2f((playerStamina * 2), 20));
	Sta.setFillColor(sf::Color(32, 157, 234));

	Endurance.setSize(sf::Vector2f((playerArmour * 2), 20));
	Endurance.setFillColor(sf::Color(175, 219, 206));

	Cha.setSize(sf::Vector2f((playerCharisma * 2), 20));
	Cha.setFillColor(sf::Color(155, 71, 216));

	Kno.setSize(sf::Vector2f((playerKnowledge * 2), 20));
	Kno.setFillColor(sf::Color(70, 234, 60));

	StrBar.setPosition(200, SkillMenuText[0].getPosition().y + 20); // these are the empty stat bars
	StaBar.setPosition(200, SkillMenuText[1].getPosition().y + 20);
	EnduranceBar.setPosition(200, SkillMenuText[2].getPosition().y + 20);
	ChaBar.setPosition(200, SkillMenuText[3].getPosition().y + 20);
	KnoBar.setPosition(200, SkillMenuText[4].getPosition().y + 20);

	Str.setPosition(200, SkillMenuText[0].getPosition().y + 20); // setting the positions to the respective bars
	Sta.setPosition(200, SkillMenuText[1].getPosition().y + 20);
	Endurance.setPosition(200, SkillMenuText[2].getPosition().y + 20);
	Cha.setPosition(200, SkillMenuText[3].getPosition().y + 20);
	Kno.setPosition(200, SkillMenuText[4].getPosition().y + 20);

	sf::Text SkillpointsLeft;
	std::string SkillsString = std::to_string(startSkillPoints);

	SkillpointsLeft.setFont(font);
	SkillpointsLeft.setFillColor(sf::Color(0, 0, 0));
	SkillpointsLeft.setString("Skillpoints Left: " + SkillsString);
	SkillpointsLeft.setCharacterSize(35);
	SkillpointsLeft.setPosition(window.getSize().x / 2.5, 400);
	window.draw(SkillpointsLeft);

	if (startSkillPoints != 0) {
		window.draw(SpendPoints);
	}


	SpendPoints.setFont(font);
	SpendPoints.setFillColor(sf::Color(255, 0, 0));
	SpendPoints.setString("You have more Skillpoints to spend");
	SpendPoints.setCharacterSize(50);
	SpendPoints.setPosition(450, 100);
	


	window.draw(StrBar);
	window.draw(StaBar);
	window.draw(EnduranceBar);
	window.draw(ChaBar);
	window.draw(KnoBar);

	window.draw(Str);
	window.draw(Sta);
	window.draw(Endurance);
	window.draw(Cha);
	window.draw(Kno);

}

void SkillMenu::draw(sf::RenderWindow &window) {
	for (int i = 0; i < skill_item_Number; i++) {
		window.draw(SkillMenuText[i]);
	}
	

}

void SkillMenu::Up() {
	if (selectedItemIndex - 1 >= 0) { // If the item index is above 0, so you cant just keep pressing up and break stuff
		SkillMenuText[selectedItemIndex].setFillColor(sf::Color::White); //set the blue color to white
		selectedItemIndex--; //decrememnt the index
		SkillMenuText[selectedItemIndex].setFillColor(sf::Color::Blue); //set the white colour to blue
	}
}

void SkillMenu::Down() {
	if (selectedItemIndex + 1 < skill_item_Number) { // If the item index is above 0, so you cant just keep pressing up and break stuff
		SkillMenuText[selectedItemIndex].setFillColor(sf::Color::White); //set the blue color to white
		selectedItemIndex++; // increment the index
		SkillMenuText[selectedItemIndex].setFillColor(sf::Color::Blue); //set the white colour to blue
	}
}