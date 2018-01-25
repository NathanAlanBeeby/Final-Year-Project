#pragma once
#include <SFML\Graphics.hpp>
class Routine
{
public:
	Routine();
	~Routine();

	enum charRoutine { ChTime, WoTime, ShTime, YaTime, BeTime, FrTime};

	int routineType;
	
	sf::Font RoutineFont;

	void Times(sf::View &view, sf::RenderWindow &window);

};

