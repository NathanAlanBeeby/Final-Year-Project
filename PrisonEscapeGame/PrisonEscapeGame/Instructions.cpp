#include "Instructions.h"



Instructions::Instructions(float width, float height)
{
	//set the background, draw it out
	if (!font.loadFromFile("../assets/text_assets/FontFile.ttf"))
	{
		// error...
		//	std::cout << "Error loading file" << std::endl;
		system("pause");
	}

	InstructionsMenuText[0].setFont(font);
	InstructionsMenuText[0].setCharacterSize(100);
	InstructionsMenuText[0].setFillColor(sf::Color::Blue);
	InstructionsMenuText[0].setString("Keys");
	InstructionsMenuText[0].setPosition(sf::Vector2f(50, 20)); // center item for width, have the amount of string items + 1, so that they're equally spaced out

	InstructionsMenuText[1].setFont(font);
	InstructionsMenuText[1].setCharacterSize(100);
	InstructionsMenuText[1].setFillColor(sf::Color::White);
	InstructionsMenuText[1].setString("Crafting");
	InstructionsMenuText[1].setPosition(sf::Vector2f(50, 120)); // center item for width, have the amount of string items + 1, so that they're equally spaced out

	InstructionsMenuText[2].setFont(font);
	InstructionsMenuText[2].setCharacterSize(100);
	InstructionsMenuText[2].setFillColor(sf::Color::White);
	InstructionsMenuText[2].setString("Skills");
	InstructionsMenuText[2].setPosition(sf::Vector2f(50, 220)); // center item for width, have the amount of string items + 1, so that they're equally spaced out

	InstructionsMenuText[3].setFont(font);
	InstructionsMenuText[3].setCharacterSize(100);
	InstructionsMenuText[3].setFillColor(sf::Color::White);
	InstructionsMenuText[3].setString("Routine");
	InstructionsMenuText[3].setPosition(sf::Vector2f(50, 320)); // center item for width, have the amount of string items + 1, so that they're equally spaced out

	InstructionsMenuText[4].setFont(font);
	InstructionsMenuText[4].setCharacterSize(100);
	InstructionsMenuText[4].setFillColor(sf::Color::White);
	InstructionsMenuText[4].setString("Back");
	InstructionsMenuText[4].setPosition(sf::Vector2f(60, height - 120)); // center item for width, have the amount of string items + 1, so that they're equally spaced out

	InstructionsMenuText[5].setFont(font);
	InstructionsMenuText[5].setCharacterSize(100);
	InstructionsMenuText[5].setFillColor(sf::Color::White);
	InstructionsMenuText[5].setString("Next");
	InstructionsMenuText[5].setPosition(sf::Vector2f(width - 160, height - 120)); // center item for width, have the amount of string items + 1, so that they're equally spaced out

	selectedItemIndex = 0;
}


Instructions::~Instructions()
{
}

void Instructions::draw(sf::RenderWindow &window) {
	for (int i = 0; i < Instructions_item_Number; i++) {
		window.draw(InstructionsMenuText[i]);
	}



}


void Instructions::Up() {
	if (selectedItemIndex - 1 >= 0) { // If the item index is above 0, so you cant just keep pressing up and break stuff
		InstructionsMenuText[selectedItemIndex].setFillColor(sf::Color::White); //set the blue color to white
		selectedItemIndex--; //decrememnt the index
		InstructionsMenuText[selectedItemIndex].setFillColor(sf::Color::Blue); //set the white colour to blue
	}
}

void Instructions::Down() {
	if (selectedItemIndex + 1 < Instructions_item_Number) { // If the item index is above 0, so you cant just keep pressing up and break stuff
		InstructionsMenuText[selectedItemIndex].setFillColor(sf::Color::White); //set the blue color to white
		selectedItemIndex++; // increment the index
		InstructionsMenuText[selectedItemIndex].setFillColor(sf::Color::Blue); //set the white colour to blue
	}
}