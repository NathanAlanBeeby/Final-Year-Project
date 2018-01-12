#include "Menu.h"



Menu::Menu(float width, float height)
{
	
	//set the background, draw it out


	if (!font.loadFromFile("../assets/text_assets/FontFile.ttf"))
	{
		// error...
		//	std::cout << "Error loading file" << std::endl;
		system("pause");
	}

	MenuText[0].setFont(font);
	MenuText[0].setCharacterSize(100);
	MenuText[0].setFillColor(sf::Color::Blue);
	MenuText[0].setString("Play");
	MenuText[0].setPosition(sf::Vector2f(width / 2.3, height / (item_Number + 2) * 1)); // center item for width, have the amount of string items + 1, so that they're equally spaced out
																						


	MenuText[1].setFont(font);
	MenuText[1].setCharacterSize(100);
	MenuText[1].setFillColor(sf::Color::White);
	MenuText[1].setString("Options");
	MenuText[1].setPosition(sf::Vector2f(width / 2.3, height / (item_Number + 2) * 2)); // center item for width, have the amount of string items + 1, so that they're equally spaced out

	MenuText[2].setFont(font);
	MenuText[2].setCharacterSize(100);
	MenuText[2].setFillColor(sf::Color::White);
	MenuText[2].setString("Exit");
	MenuText[2].setPosition(sf::Vector2f(width / 2.3, height / (item_Number + 2) * 3)); // center item for width, have the amount of string items + 1, so that they're equally spaced out

	selectedItemIndex = 0;
}


Menu::~Menu()
{
}

void Menu::draw(sf::RenderWindow &window) {
	for (int i = 0; i < item_Number; i++) {
		window.draw(MenuText[i]);
	}



}

void Menu::Up() {
	if (selectedItemIndex - 1 >= 0) { // If the item index is above 0, so you cant just keep pressing up and break stuff
		MenuText[selectedItemIndex].setFillColor(sf::Color::White); //set the blue color to white
		selectedItemIndex--; //decrememnt the index
		MenuText[selectedItemIndex].setFillColor(sf::Color::Blue); //set the white colour to blue
	}
}

void Menu::Down() {
	if (selectedItemIndex + 1 < item_Number) { // If the item index is above 0, so you cant just keep pressing up and break stuff
		MenuText[selectedItemIndex].setFillColor(sf::Color::White); //set the blue color to white
		selectedItemIndex++; // increment the index
		MenuText[selectedItemIndex].setFillColor(sf::Color::Blue); //set the white colour to blue
	}
}