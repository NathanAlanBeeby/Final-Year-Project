#pragma once
#include "SFML\Graphics.hpp"
#include <iostream>
class SkillItems
{
public:
	SkillItems();
	~SkillItems();

	sf::RectangleShape weights, bike;
	sf::Texture weightsTexture, bikeTexture;

	void WeightsBench(sf::RenderWindow &window);
	void ExercBike(sf::RenderWindow &window);

};

