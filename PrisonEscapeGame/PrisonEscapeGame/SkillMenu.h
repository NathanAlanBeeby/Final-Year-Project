#pragma once

#include <SFML/Graphics.hpp>
#define skill_item_Number 7

class SkillMenu
{
public:
	SkillMenu(float width, float height);
	~SkillMenu();

	void drawBars(sf::RenderWindow &window);
	void draw(sf::RenderWindow &window);
	void Up();
	void Down();
	int GetPressedItem() { return selectedItemIndex; }

	int playerStrength = 0;
	int playerStamina = 0;
	int playerArmour = 0;
	int playerCharisma = 0;
	int playerKnowledge = 0;
	int startSkillPoints = 10;

	sf::Text SpendPoints;

	sf::RectangleShape StrBar, StaBar, EnduranceBar, ChaBar, KnoBar;
	sf::RectangleShape Str, Sta, Endurance, Cha, Kno;

private:
	int selectedItemIndex;
	sf::Font font;
	sf::Text SkillMenuText[skill_item_Number];
};

