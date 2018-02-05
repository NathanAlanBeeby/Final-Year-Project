#include "prisonerDialogue.h"

prisonerDialogue::prisonerDialogue()
{
	if (!font.loadFromFile("../assets/text_assets/FontFile.ttf"))
	{
		// error...
		//	std::cout << "Error loading file" << std::endl;
		system("pause");
	}

	

	PrisonerText[0].setFont(font);
	PrisonerText[0].setCharacterSize(50);
	PrisonerText[0].setFillColor(sf::Color::Blue);
	PrisonerText[0].setString("Talk");
	

	PrisonerText[1].setFont(font);
	PrisonerText[1].setCharacterSize(50);
	PrisonerText[1].setFillColor(sf::Color::Black);
	PrisonerText[1].setString("Trade");
	
	PrisonerText[2].setFont(font);
	PrisonerText[2].setCharacterSize(50);
	PrisonerText[2].setFillColor(sf::Color::Black);
	PrisonerText[2].setString("Mission");


	prisonItemIndex = 0;

	

	
}


prisonerDialogue::~prisonerDialogue()
{
}
void prisonerDialogue::drawDialogueBox(sf::View &view, sf::RenderWindow &window) {
	DialogueBox.setSize(sf::Vector2f(400, 200));
	DialogueBox.setFillColor(sf::Color(239, 239, 167));
	DialogueBox.setOutlineThickness(2);
	DialogueBox.setOutlineColor(sf::Color(0, 0, 0, 255));
	DialogueBox.setPosition(view.getCenter().x - 200, view.getCenter().y + 80);

	window.draw(DialogueBox);
	
	
}

void prisonerDialogue::draw(sf::View &view, sf::RenderWindow &window) {
	std::vector<sf::RectangleShape>  BoxSegment(3, sf::RectangleShape(segBox)); // an array of 5 cell doors

	for (int i = 0; i < BoxSegment.size(); i++) {

		BoxSegment[i].setSize(sf::Vector2f(DialogueBox.getSize().x - 40, 50));
		BoxSegment[i].setFillColor(sf::Color(255, 0, 0));
		BoxSegment[i].setOutlineThickness(1);
		BoxSegment[i].setOutlineColor(sf::Color(0, 0, 0, 255));
	}
	int offset = 12;

	BoxSegment[0].setPosition(DialogueBox.getPosition().x + 20, DialogueBox.getPosition().y + offset);
	BoxSegment[1].setPosition(DialogueBox.getPosition().x + 20, BoxSegment[0].getPosition().y + offset + 50);
	BoxSegment[2].setPosition(DialogueBox.getPosition().x + 20, BoxSegment[1].getPosition().y + offset + 50);

	

	for (int i = 0; i < BoxSegment.size(); i++) {
		window.draw(BoxSegment[i]);
	}
	PrisonerText[0].setPosition(view.getCenter().x, view.getCenter().y + 80); // center item for width, have the amount of string items + 1, so that they're equally spaced out
	PrisonerText[1].setPosition(view.getCenter().x, view.getCenter().y + 140); // center item for width, have the amount of string items + 1, so that they're equally spaced out
	PrisonerText[2].setPosition(view.getCenter().x, view.getCenter().y + 200); // center item for width, have the amount of string items + 1, so that they're equally spaced out


	for (int i = 0; i < prisoner_item_Number; i++) {
		window.draw(PrisonerText[i]);
	}
}

void prisonerDialogue::Up() {
	if (prisonItemIndex - 1 >= 0) { // If the item index is above 0, so you cant just keep pressing up and break stuff
		PrisonerText[prisonItemIndex].setFillColor(sf::Color::Black); //set the blue color to white
		prisonItemIndex--; //decrememnt the index
		PrisonerText[prisonItemIndex].setFillColor(sf::Color::Blue); //set the white colour to blue
	}
}

void prisonerDialogue::Down() {
	if (prisonItemIndex + 1 < prisoner_item_Number) { // If the item index is above 0, so you cant just keep pressing up and break stuff
		PrisonerText[prisonItemIndex].setFillColor(sf::Color::Black); //set the blue color to white
		prisonItemIndex++; // increment the index
		PrisonerText[prisonItemIndex].setFillColor(sf::Color::Blue); //set the white colour to blue
	}
}


void prisonerDialogue::Talk(sf::View &view, sf::RenderWindow &window) {
	std::vector<sf::Text>  talking(7, sf::Text(TalkDialogue)); // an array of 5 cell doorsa

	talking[0].setString("Prisoner Text 1");
	talking[1].setString("Prisoner Text 2");
	talking[2].setString("Prisoner Text 3");
	talking[3].setString("Prisoner Text 4");
	talking[4].setString("Prisoner Text 5");
	talking[5].setString("Prisoner Text 6");
	talking[6].setString("Prisoner Text 7");

	for (int i = 0; i < talking.size(); i++) {
		talking[i].setFont(font);
		talking[i].setCharacterSize(40);
		talking[i].setFillColor(sf::Color(0, 0, 0));
		talking[i].setPosition(view.getCenter().x - 20, view.getCenter().y + 90);
	}

	if (talkInt == 0) { window.draw(talking[0]); }
	if (talkInt == 1) { window.draw(talking[1]); }
	if (talkInt == 2) { window.draw(talking[2]); }
	if (talkInt == 3) { window.draw(talking[3]); }
	if (talkInt == 4) { window.draw(talking[4]); }
	if (talkInt == 5) { window.draw(talking[5]); }
	if (talkInt == 6) { window.draw(talking[6]); }
}

void prisonerDialogue::Trade(sf::View &view, sf::RenderWindow &window) {
	if (!tradeTexture.loadFromFile("../assets/image_assets/TradeSymbol.png")) {
		std::cout << "Load fail Error on playerFaceTexture" << std::endl;
		system("pause");
	}
	std::vector<sf::RectangleShape>  Boxes(4, sf::RectangleShape(tradeBox)); // an array of 5 cell doorsa
	for (int i = 0; i < Boxes.size(); i++) {
		Boxes[i].setSize(sf::Vector2f(50, 50));
		Boxes[i].setFillColor(sf::Color(155, 155, 155));
		Boxes[i].setOutlineThickness(2);
		Boxes[i].setOutlineColor(sf::Color(0, 0, 0));
	}

	Boxes[0].setPosition(view.getCenter().x - 160, view.getCenter().y + 120);
	Boxes[1].setPosition(view.getCenter().x - 160, view.getCenter().y + 170);
	Boxes[2].setPosition(view.getCenter().x + 110, view.getCenter().y + 120);
	Boxes[3].setPosition(view.getCenter().x + 110, view.getCenter().y + 170);

	tradeSymbol.setSize(sf::Vector2f(200, 100));
	tradeSymbol.setTexture(&tradeTexture);
	tradeSymbol.setPosition(view.getCenter().x - 100, view.getCenter().y + 120);
	for (int i = 0; i < Boxes.size(); i++) {
		window.draw(Boxes[i]);
	}
	window.draw(tradeSymbol);

}

void prisonerDialogue::Mission(sf::View &view, sf::RenderWindow &window) {
}