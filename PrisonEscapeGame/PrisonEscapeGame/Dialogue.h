#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
class Dialogue
{
public:
	Dialogue();
	~Dialogue();

	sf::RectangleShape DialogueBox, segBox;
	sf::Font font;
	bool dialogueOpen = false;
	void drawDialogue(sf::View &view, sf::RenderWindow &window);
	void prisonerDialogue(sf::View &view, sf::RenderWindow &window);
	void guardDialogue(sf::View &view, sf::RenderWindow &window);
};

