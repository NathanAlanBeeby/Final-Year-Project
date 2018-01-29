#pragma once
#include <SFML\Graphics.hpp>
#include <iostream>
class furnitureInv
{
public:
	furnitureInv();
	~furnitureInv();

	sf::RectangleShape gridBox;

	void Grid2by2(sf::View &view, sf::RenderWindow &window);
	void Grid5by2(sf::View &view, sf::RenderWindow &window);
	void Grid4by4(sf::View &view, sf::RenderWindow &window);


	sf::RectangleShape bin, desk, locker, BigBin, toolsCabinet, footLocker;
	sf::Texture binTexture, deskTexture, lockerTexture, BigBinTexture, toolsCabinetTexture, footLockerTexture;

	void drawBin(sf::View &view, sf::RenderWindow &window);
	void drawDesk(sf::View &view, sf::RenderWindow &window);
	void drawLocker(sf::View &view, sf::RenderWindow &window);
	void drawBigBin(sf::View &view, sf::RenderWindow &window);
	void drawToolsCabinet(sf::View &view, sf::RenderWindow &window);
	void drawFootLocker(sf::View &view, sf::RenderWindow &window);
};

