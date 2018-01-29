#include "Dialogue.h"



Dialogue::Dialogue()
{
}


Dialogue::~Dialogue()
{
}

void Dialogue::drawDialogue(sf::View &view, sf::RenderWindow &window) {
	if (!font.loadFromFile("../assets/text_assets/CagedPrisoner.ttf")) {
		std::cout << "Load fail Error on dialoguefont" << std::endl;
		system("pause");
	}
	DialogueBox.setSize(sf::Vector2f(400, 200));
	DialogueBox.setFillColor(sf::Color(239, 239, 167));
	DialogueBox.setOutlineThickness(2);
	DialogueBox.setOutlineColor(sf::Color(0, 0, 0, 255));
	DialogueBox.setPosition(view.getCenter().x - 200, view.getCenter().y + 80);


	std::vector<sf::RectangleShape>  BoxSegment(3, sf::RectangleShape(segBox)); // an array of 5 cell doors

	for (int i = 0; i < BoxSegment.size(); i++) {

		BoxSegment[i].setSize(sf::Vector2f(DialogueBox.getSize().x - 40, 50));
		BoxSegment[i].setFillColor(sf::Color(232, 232, 139));
		BoxSegment[i].setOutlineThickness(1);
		BoxSegment[i].setOutlineColor(sf::Color(0, 0, 0, 255));
	}
	int offset = 12;

	BoxSegment[0].setPosition(DialogueBox.getPosition().x + 20, DialogueBox.getPosition().y + offset);
	BoxSegment[1].setPosition(DialogueBox.getPosition().x + 20, BoxSegment[0].getPosition().y + offset + 50);
	BoxSegment[2].setPosition(DialogueBox.getPosition().x + 20, BoxSegment[1].getPosition().y + offset + 50);

	sf::Text dialogueText;
	std::vector<sf::Text>  BoxText(3, sf::Text(dialogueText)); // an array of 5 cell doors

	for (int i = 0; i < BoxText.size(); i++) {
		BoxText[i].setFont(font);
		BoxText[i].setCharacterSize(20);
		BoxText[i].setFillColor(sf::Color(0, 0, 0));
	}

	BoxText[0].setString("Talk");
	BoxText[0].setPosition(BoxSegment[0].getPosition().x + 170, BoxSegment[0].getPosition().y + 12);

	BoxText[1].setString("Trade");
	BoxText[1].setPosition(BoxSegment[1].getPosition().x + 170, BoxSegment[1].getPosition().y + 12);

	BoxText[2].setString("Request Mission");
	BoxText[2].setPosition(BoxSegment[2].getPosition().x + 100, BoxSegment[2].getPosition().y + 12);




	window.draw(DialogueBox);

	for (int i = 0; i < BoxSegment.size(); i++) {
		window.draw(BoxSegment[i]);
	}
	for (int i = 0; i < BoxText.size(); i++) {
		window.draw(BoxText[i]);
	}


}

void Dialogue::prisonerDialogue(sf::View &view, sf::RenderWindow &window) {

}

void Dialogue::guardDialogue(sf::View &view, sf::RenderWindow &window) {

}