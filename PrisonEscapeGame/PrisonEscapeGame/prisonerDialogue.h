#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#define prisoner_item_Number 3

class prisonerDialogue
{
public:
	prisonerDialogue();
	~prisonerDialogue();

	sf::RectangleShape DialogueBox, segBox;

	void drawDialogueBox(sf::View &view, sf::RenderWindow &window);
	void draw(sf::View &view, sf::RenderWindow &window);

	void Up();
	void Down();
	int GetPressedItem() { return prisonItemIndex; }

	sf::Texture tradeTexture;
	sf::RectangleShape tradeBox, tradeSymbol;

	void Talk(sf::View &view, sf::RenderWindow &window);
	void Trade(sf::View &view, sf::RenderWindow &window);
	void Mission(sf::View &view, sf::RenderWindow &window);


	sf::Text TalkDialogue;
	int talkInt = rand() % 6;
private:
	int prisonItemIndex;
	sf::Font font;
	sf::Text PrisonerText[prisoner_item_Number];
};

