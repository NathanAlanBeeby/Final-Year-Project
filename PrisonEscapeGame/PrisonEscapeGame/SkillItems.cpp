#include "SkillItems.h"



SkillItems::SkillItems()
{
}


SkillItems::~SkillItems()
{
}

void SkillItems::WeightsBench(sf::RenderWindow &window) {
	if (!weightsTexture.loadFromFile("../assets/image_assets/WeightsBench.png")) {
		std::cout << "Load fail Error on weights bench" << std::endl;
		system("pause");

	}

	std::vector<sf::RectangleShape>  Weights(6, sf::RectangleShape(weights)); // an array of 5 cell doorsa

	for (int i = 0; i < Weights.size(); i++) {

		Weights[i].setSize(sf::Vector2f(128, 64));
		Weights[i].setTexture(&weightsTexture);

	}



	Weights[0].setPosition((1 * 64), (42 * 64));
	Weights[1].setPosition((1 * 64), (45 * 64));
	Weights[2].setPosition((1 * 64), (48 * 64));
	Weights[3].setPosition((1 * 64), (51 * 64));
	Weights[4].setPosition((1 * 64), (54 * 64));
	Weights[5].setPosition((1 * 64), (57 * 64));


	for (int i = 0; i < Weights.size(); i++) {
		window.draw(Weights[i]);
	}
}
void SkillItems::ExercBike(sf::RenderWindow &window) {
	if (!bikeTexture.loadFromFile("../assets/image_assets/Bike.png")) {
		std::cout << "Load fail Error on bike texture" << std::endl;
		system("pause");

	}
	std::vector<sf::RectangleShape>  Bike(6, sf::RectangleShape(bike)); // an array of 5 cell doorsa

	for (int i = 0; i < Bike.size(); i++) {

		Bike[i].setSize(sf::Vector2f(64, 64));
		Bike[i].setTexture(&bikeTexture);

	}



	Bike[0].setPosition((19 * 64), (42 * 64));
	Bike[1].setPosition((19 * 64), (45 * 64));
	Bike[2].setPosition((19 * 64), (48 * 64));
	Bike[3].setPosition((19 * 64), (51 * 64));
	Bike[4].setPosition((19 * 64), (54 * 64));
	Bike[5].setPosition((19 * 64), (57 * 64));



	for (int i = 0; i < Bike.size(); i++) {
		window.draw(Bike[i]);
	}
}