#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include "Collision.h"
class Furniture
{
	// 1 x 1 Objects - Sink and toilet, office chair, locker, shower head
	// 1 x 5 Objects - Caffeteria Bench, 
	// 2 x 1 Objects - Office Desk, Cell Block TV, Sofa, Footlocker, prison bed
	// 2 x 2 Objects - Medical Bed
	// 2 x 5 Objects - Serving Table, Cafeteria Table
public:
	
	Collision getCollision() {
		return Collision(cellDoor);	return Collision(averageDoor);	return Collision(solitaryDoor);	return Collision(securityDoor);
		return Collision(toiletSink);	return Collision(officeChair);	return Collision(locker);	return Collision(showerHead); return Collision(TrashCan);	return Collision(PayPhone);	return Collision(DrainPipe);	return Collision(WashingMachine);	return Collision(LaundryBasket);
		return Collision(caffeteriaBench);	return Collision(officeDesk);	return Collision(cbTV);	return Collision(sofa); return Collision(footlocker);	return Collision(prisonBed);	return Collision(medicalBed);	return Collision(MopAndBucket);	return Collision(Bookshelf);	return Collision(MicrowaveKettle);
		return Collision(CafBench);	return Collision(CafTable);	return Collision(ServTable);	return Collision(Visitation);	return Collision(WardDesk);
		return Collision(WorkBench);	return Collision(Sander);	return Collision(ToolsCabinet);	return Collision(Dumpster);	return Collision(TimberStorage);	return Collision(JigSaw);
	}
	
	sf::RectangleShape cellDoor, averageDoor, solitaryDoor, securityDoor; //1x1 - DOORS
	sf::Texture cellTexture, averageDoorTexture, solitaryTexture, securityTexture;



	sf::RectangleShape toiletSink, officeChair, locker, showerHead, TrashCan, PayPhone, DrainPipe, WashingMachine, LaundryBasket; //1x1
	sf::Texture toiletTexture, chairTexture, lockerTexture, showerTexture, TrashTexture, PhoneTexture, DrainTexture, WashingTexture, LBasketTexture;
	
	sf::RectangleShape caffeteriaBench; //1x5

	sf::RectangleShape officeDesk, cbTV, sofa, footlocker, prisonBed, medicalBed, MopAndBucket, Bookshelf, MicrowaveKettle; //2x?
	sf::Texture DeskTexture, TVTexture, SofaTexture, FtLockerTexture, bedTexture, medbedTexture, MopTexture, BookTexture, MicrowaveTexture;

	sf::RectangleShape CafBench, CafTable, ServTable, Visitation, WardDesk; 
	sf::Texture BenchTexture, TableTexture, ServTexture, VisitTexture, WardenTexture;

	sf::RectangleShape WorkBench, Sander, ToolsCabinet, Dumpster, TimberStorage, JigSaw;
	sf::Texture WorkBenchTexture, SanderTexture, ToolsCabinetTexture, DumpsterTexture, TimberTexture, JigSawTexture;
	
	

	Furniture();
	~Furniture();

	void Doors(sf::RenderWindow &window);

	void smallFurniture(sf::RenderWindow &window);

	void mediumFurniture(sf::RenderWindow &window);

	void largeFurniture(sf::RenderWindow &window);

	void WorkShop(sf::RenderWindow &window);

	
	
};

