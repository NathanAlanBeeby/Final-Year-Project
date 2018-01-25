#pragma once
#include <SFML/Graphics.hpp>
#define Instructions_item_Number 6
class Instructions
{
public:
	Instructions(float width, float height);
	~Instructions();

	void draw(sf::RenderWindow &window);
	void Up();
	void Down();
	int GetPressedItem() { return selectedItemIndex; }

private:
	int selectedItemIndex;
	sf::Font font;
	sf::Text InstructionsMenuText[Instructions_item_Number];
};

