#include "guardDialogue.h"


guardDialogue::guardDialogue()
{
	if (!font.loadFromFile("../assets/text_assets/FontFile.ttf"))
	{
		// error...
		//	std::cout << "Error loading file" << std::endl;
		system("pause");
	}
	GuardText[0].setFont(font);
	GuardText[0].setCharacterSize(50);
	GuardText[0].setFillColor(sf::Color::Blue);
	GuardText[0].setString("Talk");



	GuardText[1].setFont(font);
	GuardText[1].setCharacterSize(50);
	GuardText[1].setFillColor(sf::Color::Black);
	GuardText[1].setString("Snitch");

	GuardText[2].setFont(font);
	GuardText[2].setCharacterSize(50);
	GuardText[2].setFillColor(sf::Color::Black);
	GuardText[2].setString("Mission");



	guardItemIndex = 0;
}


guardDialogue::~guardDialogue()
{
}
void guardDialogue::drawDialogueBox(sf::View &view, sf::RenderWindow &window) {
	DialogueBox.setSize(sf::Vector2f(400, 200));
	DialogueBox.setFillColor(sf::Color(239, 239, 167));
	DialogueBox.setOutlineThickness(2);
	DialogueBox.setOutlineColor(sf::Color(0, 0, 0, 255));
	DialogueBox.setPosition(view.getCenter().x - 200, view.getCenter().y + 80);

	

	window.draw(DialogueBox);

	
}

void guardDialogue::draw(sf::View &view, sf::RenderWindow &window) {
	std::vector<sf::RectangleShape>  BoxSegment(3, sf::RectangleShape(segBox)); // an array of 5 cell doors

	for (int i = 0; i < BoxSegment.size(); i++) {

		BoxSegment[i].setSize(sf::Vector2f(DialogueBox.getSize().x - 40, 50));
		BoxSegment[i].setFillColor(sf::Color(0, 213, 255));
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
	GuardText[0].setPosition(view.getCenter().x, view.getCenter().y + 80); // center item for width, have the amount of string items + 1, so that they're equally spaced out
	GuardText[1].setPosition(view.getCenter().x, view.getCenter().y + 140); // center item for width, have the amount of string items + 1, so that they're equally spaced out
	GuardText[2].setPosition(view.getCenter().x, view.getCenter().y + 200); // center item for width, have the amount of string items + 1, so that they're equally spaced out


	for (int i = 0; i < guard_item_Number; i++) {
		window.draw(GuardText[i]);
	}
}

void guardDialogue::Up() {
	if (guardItemIndex - 1 >= 0) { // If the item index is above 0, so you cant just keep pressing up and break stuff
		GuardText[guardItemIndex].setFillColor(sf::Color::Black); //set the blue color to white
		guardItemIndex--; //decrememnt the index
		GuardText[guardItemIndex].setFillColor(sf::Color::Blue); //set the white colour to blue
	}
}

void guardDialogue::Down() {
	if (guardItemIndex + 1 < guard_item_Number) { // If the item index is above 0, so you cant just keep pressing up and break stuff
		GuardText[guardItemIndex].setFillColor(sf::Color::Black); //set the blue color to white
		guardItemIndex++; // increment the index
		GuardText[guardItemIndex].setFillColor(sf::Color::Blue); //set the white colour to blue
	}
}

void guardDialogue::Talk(sf::View &view, sf::RenderWindow &window) {
	std::vector<sf::Text>  talking(7, sf::Text(TalkDialogue)); // an array of 5 cell doorsa

	talking[0].setString("Guard Text 1");
	talking[1].setString("Guard Text 2");
	talking[2].setString("Guard Text 3");
	talking[3].setString("Guard Text 4");
	talking[4].setString("Guard Text 5");
	talking[5].setString("Guard Text 6");
	talking[6].setString("Guard Text 7");

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

void guardDialogue::Snitch(sf::View &view, sf::RenderWindow &window){
	std::vector<sf::Text>  snitching(4, sf::Text(TalkDialogue)); // an array of 5 cell doorsa

	snitching[0].setString("No information for guard");
	snitching[0].setPosition(view.getCenter().x - 100, view.getCenter().y + 90);
	snitching[1].setString("Guard: Get out of here, punk!");
	snitching[1].setPosition(view.getCenter().x - 100, view.getCenter().y + 140);

	snitching[2].setPosition(view.getCenter().x - 100, view.getCenter().y + 90);
	snitching[2].setString("You give the information to the guard");
	snitching[3].setPosition(view.getCenter().x - 100, view.getCenter().y + 140);
	snitching[3].setString("Guard: Nice Work!");


	for (int i = 0; i < snitching.size(); i++) {
		snitching[i].setFont(font);
		snitching[i].setCharacterSize(40);
		snitching[i].setFillColor(sf::Color(0, 0, 0));
		
	}
	if (prisonInfo == 0) {
		window.draw(snitching[0]);
		window.draw(snitching[1]);
	}
	else if (prisonInfo >= 1) {
		window.draw(snitching[2]);
		window.draw(snitching[3]);
		prisonInfo = 0;
	}

}

void guardDialogue::Mission(sf::View &view, sf::RenderWindow &window){
}