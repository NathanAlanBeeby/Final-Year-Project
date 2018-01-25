#pragma once
#include <SFML\Graphics.hpp>
#include <iostream>
class prisonWalls
{
public:
	prisonWalls();
	~prisonWalls();

	sf::RectangleShape wallBlock;
	sf::Texture wallTexture;

	int topOuterWall, bottomOuterWall, leftOuterWall;
	int rightOuterSeg1, rightOuterSeg2, rightOuterSeg3;

	int showerWall, cellBigWall, showerMidWall, cellMediumWall, cellSmallWall;
	int wallSize;
	int wardenWallSize, caffeterianWallSize, yardWallSize, workInnerWallsSize, solInnerWallsSize;

	void outerWalls(sf::RenderWindow &window);



	void cellblockInnerWalls(sf::RenderWindow &window);
	void medicalInnerWalls(sf::RenderWindow &window);
	void wardenVisitationInnerWalls(sf::RenderWindow &window);
	void closetAndCafInnerWalls(sf::RenderWindow &window);
	void yardInnerWalls(sf::RenderWindow &window);
	void workLaundSecInnerWalls(sf::RenderWindow &window);
	void solitaryLibraryInnerWalls(sf::RenderWindow &window);
};

