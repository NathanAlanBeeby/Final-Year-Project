#pragma once
#include <SFML\Graphics.hpp>
#define Options_item_Number 4


class OptionsMenu
{
public:
	OptionsMenu(float width, float height);
	~OptionsMenu();

	void draw(sf::RenderWindow &window);
	void Up();
	void Down();
	void drawBars(sf::RenderWindow &window);
	int GetPressedItem() { return selectedItemIndex; }
	float Music = 50.0f;
	int Sound = 50;

	sf::RectangleShape emptyMusic, emptySound;
	sf::RectangleShape MusicBar, SoundBar;


private:
	int selectedItemIndex;
	sf::Font font;
	sf::Text OptionsMenuText[Options_item_Number];
};

