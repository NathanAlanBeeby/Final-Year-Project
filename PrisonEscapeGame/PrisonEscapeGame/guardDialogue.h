#pragma once

#include <SFML/Graphics.hpp>
#define guard_item_Number 3

class guardDialogue
{
public:
	guardDialogue();
	~guardDialogue();

	sf::RectangleShape DialogueBox, segBox;

	void drawDialogueBox(sf::View &view, sf::RenderWindow &window);
	void draw(sf::View &view, sf::RenderWindow &window);
	void Up();
	void Down();
	int GetPressedItem() { return guardItemIndex; }

	void Talk(sf::View &view, sf::RenderWindow &window);
	void Snitch(sf::View &view, sf::RenderWindow &window);
	void Mission(sf::View &view, sf::RenderWindow &window);
	sf::Text TalkDialogue;
	int talkInt = rand() % 6;
	int prisonInfo = 0; // int for number of information collected on prisoner


private:
	int guardItemIndex;
	sf::Font font;
	sf::Text GuardText[guard_item_Number];
};

