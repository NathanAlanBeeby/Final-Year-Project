#include "Furniture.h"
#include <iostream>

Furniture::Furniture()
{
}


Furniture::~Furniture()
{
}


void Furniture::Doors(sf::RenderWindow &window) {
	if (!cellTexture.loadFromFile("../assets/image_assets/cellDoor.png")) {
		std::cout << "Load fail Error on cellTexture" << std::endl;
		system("pause");

	}

	if (!averageDoorTexture.loadFromFile("../assets/image_assets/averageDoor.png")) {
		std::cout << "Load fail Error on averageDoorTexture" << std::endl;
		system("pause");

	}

	if (!solitaryTexture.loadFromFile("../assets/image_assets/solitaryDoor.png")) {
		std::cout << "Load fail Error on solitaryTexture" << std::endl;
		system("pause");

	}

	if (!securityTexture.loadFromFile("../assets/image_assets/securityDoor.png")) {
		std::cout << "Load fail Error on securityDoorTexture" << std::endl;
		system("pause");

	}

	

	std::vector<sf::RectangleShape>  DoorOfCell(5, sf::RectangleShape(cellDoor)); // an array of 5 cell doors

	for (int i = 0; i < DoorOfCell.size(); i++) {
		
		DoorOfCell[i].setSize(sf::Vector2f(64, 64));
		DoorOfCell[i].setTexture(&cellTexture);
		
	}

	

	DoorOfCell[0].setPosition((11*64), (6*64));
	DoorOfCell[1].setPosition((16 * 64), (6 * 64));
	DoorOfCell[2].setPosition((21 * 64), (6 * 64));
	DoorOfCell[3].setPosition((26 * 64), (6 * 64));
	DoorOfCell[4].setPosition((31 * 64), (6 * 64));


	for (int i = 0; i < DoorOfCell.size(); i++) {
		window.draw(DoorOfCell[i]);
	}

	std::vector<sf::RectangleShape>  DoorAver(6, sf::RectangleShape(averageDoor)); // an array of 5 cell doors

	for (int i = 0; i < DoorAver.size(); i++) {
		DoorAver[i].setSize(sf::Vector2f(64, 64));
		DoorAver[i].setTexture(&averageDoorTexture);

	}

	DoorAver[0].setPosition((9 * 64), (10 * 64)); // shower door
	
	DoorAver[0].setRotation(90);

	DoorAver[1].setPosition((2 * 64), (24 * 64));
	DoorAver[2].setPosition((13 * 64), (24 * 64));
	DoorAver[3].setPosition((2 * 64), (34 * 64));
	DoorAver[4].setPosition((18 * 64), (24 * 64));
	DoorAver[5].setPosition((18 * 64), (34 * 64));

	for (int i = 0; i < DoorAver.size(); i++) {
		window.draw(DoorAver[i]);
	}

	std::vector<sf::RectangleShape>  DoorSolitary(19, sf::RectangleShape(solitaryDoor)); // an array of 5 cell doorsa

	for (int i = 0; i < DoorSolitary.size(); i++) {
		DoorSolitary[i].setSize(sf::Vector2f(64, 64));
		DoorSolitary[i].setTexture(&solitaryTexture);

	}

	DoorSolitary[0].setPosition((2 * 64), (38 * 64));
	DoorSolitary[1].setPosition((2 * 64), (61 * 64));

	DoorSolitary[2].setPosition((22 * 64), (59 * 64)); // yard door
	DoorSolitary[2].setRotation(90);

	DoorSolitary[3].setPosition((27 * 64), (58 * 64));
	DoorSolitary[4].setPosition((33 * 64), (54 * 64));
	DoorSolitary[5].setPosition((27 * 64), (54 * 64));
	DoorSolitary[6].setPosition((42 * 64), (58 * 64));

	DoorSolitary[7].setPosition((34 * 64), (17 * 64));
	
	DoorSolitary[7].rotate(90);
	
	DoorSolitary[8].setPosition((38 * 64), (5 * 64)); // med office 1

	DoorSolitary[8].setRotation(90);

	DoorSolitary[9].setPosition((38 * 64), (12 * 64)); // med office 2

	DoorSolitary[9].setRotation(90);

	DoorSolitary[10].setPosition((38 * 64), (20 * 64)); // wardens office

	DoorSolitary[10].setRotation(90);

	DoorSolitary[11].setPosition((2 * 64), (65 * 64));
	DoorSolitary[12].setPosition((6 * 64), (65 * 64));
	DoorSolitary[13].setPosition((10 * 64), (65 * 64));
	DoorSolitary[14].setPosition((14 * 64), (65 * 64));
	DoorSolitary[15].setPosition((18 * 64), (65 * 64));
	DoorSolitary[16].setPosition((22 * 64), (65 * 64));

	DoorSolitary[17].setPosition((45 * 64), (36 * 64));
	DoorSolitary[17].setRotation(90);

	DoorSolitary[18].setPosition((45 * 64), (56 * 64));
	DoorSolitary[18].setRotation(90);

	for (int i = 0; i < DoorSolitary.size(); i++) {
		window.draw(DoorSolitary[i]);
	}

	std::vector<sf::RectangleShape>  DoorSecurity(2, sf::RectangleShape(securityDoor)); // an array of 5 cell doorsa

	for (int i = 0; i < DoorSecurity.size(); i++) {
		DoorSecurity[i].setSize(sf::Vector2f(64, 64));
		DoorSecurity[i].setTexture(&securityTexture);

	}

	DoorSecurity[0].setPosition((27 * 64), (38 * 64));
	DoorSecurity[1].setPosition((27 * 64), (34 * 64));
	
	for (int i = 0; i < DoorSecurity.size(); i++) {
		window.draw(DoorSecurity[i]);
	}





}

void Furniture::smallFurniture(sf::RenderWindow &window) {
	if (!toiletTexture.loadFromFile("../assets/image_assets/SinkToilet.png")) {
		std::cout << "Load fail Error on cellTexture" << std::endl;
		system("pause");

	}

	if (!chairTexture.loadFromFile("../assets/image_assets/Chair.png")) {
		std::cout << "Load fail Error on cellTexture" << std::endl;
		system("pause");

	}

	if (!lockerTexture.loadFromFile("../assets/image_assets/locker.png")) {
		std::cout << "Load fail Error on cellTexture" << std::endl;
		system("pause");

	}

	if (!showerTexture.loadFromFile("../assets/image_assets/Shower.png")) {
		std::cout << "Load fail Error on cellTexture" << std::endl;
		system("pause");

	}
	if (!PhoneTexture.loadFromFile("../assets/image_assets/PayPhone.png")) {
		std::cout << "Load fail Error on cellTexture" << std::endl;
		system("pause");

	}

	if (!DrainTexture.loadFromFile("../assets/image_assets/ManHole.png")) {
		std::cout << "Load fail Error on cellTexture" << std::endl;
		system("pause");

	}

	if (!TrashTexture.loadFromFile("../assets/image_assets/TrashBin.png")) {
		std::cout << "Load fail Error on cellTexture" << std::endl;
		system("pause");

	}

	if (!WashingTexture.loadFromFile("../assets/image_assets/Washer.png")) {
		std::cout << "Load fail Error on cellTexture" << std::endl;
		system("pause");

	}
	if (!LBasketTexture.loadFromFile("../assets/image_assets/WashingBasket.png")) {
		std::cout << "Load fail Error on cellTexture" << std::endl;
		system("pause");

	}
	
	std::vector<sf::RectangleShape>  SinkandToilet(11, sf::RectangleShape(toiletSink)); // an array of 5 cell doorsa

	for (int i = 0; i < SinkandToilet.size(); i++) {
		SinkandToilet[i].setSize(sf::Vector2f(64, 64));
		SinkandToilet[i].setTexture(&toiletTexture);

	}

	SinkandToilet[0].setPosition((12 * 64), (1 * 64));
	SinkandToilet[1].setPosition((17 * 64), (1 * 64));
	SinkandToilet[2].setPosition((22 * 64), (1 * 64));
	SinkandToilet[3].setPosition((27 * 64), (1 * 64));
	SinkandToilet[4].setPosition((32 * 64), (1 * 64));

	SinkandToilet[5].setPosition((3 * 64), (66 * 64));
	SinkandToilet[6].setPosition((7 * 64), (66 * 64));
	SinkandToilet[7].setPosition((11 * 64), (66 * 64));
	SinkandToilet[8].setPosition((15 * 64), (66 * 64));
	SinkandToilet[9].setPosition((19 * 64), (66 * 64));
	SinkandToilet[10].setPosition((23 * 64), (66 * 64));

	for (int i = 0; i < SinkandToilet.size(); i++) {
		window.draw(SinkandToilet[i]);
	}



	std::vector<sf::RectangleShape>  Chair(7, sf::RectangleShape(officeChair)); // an array of 5 cell doorsa

	for (int i = 0; i < Chair.size(); i++) {
		Chair[i].setSize(sf::Vector2f(64, 64));
		Chair[i].setTexture(&chairTexture);

	}

	Chair[0].setPosition((38 * 64), (2 * 64)); // med room 1 desk
	Chair[1].setPosition((38 * 64), (9 * 64)); // med room 2 desk
	Chair[2].setPosition((38 * 64), (16 * 64)); // warden room desk 1
	Chair[3].setPosition((42 * 64), (16 * 64)); // warden room desk 2
	Chair[4].setPosition((40 * 64), (50 * 64)); // desk 1 operating room
	Chair[5].setPosition((36 * 64), (50 * 64)); // desk 2 operating room
	Chair[6].setPosition((32 * 64), (50 * 64)); // desk 3 operating room


	for (int i = 0; i < Chair.size(); i++) {
		window.draw(Chair[i]);
	}


	std::vector<sf::RectangleShape>  Cabinet(10, sf::RectangleShape(locker)); // an array of 5 cell doorsa

	for (int i = 0; i < Cabinet.size(); i++) {
		Cabinet[i].setSize(sf::Vector2f(64, 64));
		Cabinet[i].setTexture(&lockerTexture);

	}

	Cabinet[0].setPosition((40 * 64), (1 * 64)); // med room 1 cabinet
	Cabinet[1].setPosition((40 * 64), (8 * 64)); // med room 2 cabinet
	Cabinet[2].setPosition((40 * 64), (15 * 64)); // warden room cabinet 1
	Cabinet[3].setPosition((41 * 64), (15 * 64)); // warden room cabinet 2

	
	Cabinet[4].setPosition((34 * 64), (49 * 64)); // cabinet 1 operating room
	Cabinet[5].setPosition((35 * 64), (49 * 64)); // cabinet 2 operating room
	Cabinet[6].setPosition((38 * 64), (49 * 64)); // cabinet 3 operating room
	Cabinet[7].setPosition((39 * 64), (49 * 64)); // cabinet 4 operating room

	Cabinet[8].setPosition((42 * 64), (49 * 64)); // cabinet 5 operating room
	Cabinet[9].setPosition((43 * 64), (49 * 64)); // cabinet 6 operating room

	for (int i = 0; i < Cabinet.size(); i++) {
		window.draw(Cabinet[i]);
	}


	std::vector<sf::RectangleShape>  Bin(11, sf::RectangleShape(TrashCan)); // an array of 5 cell doorsa

	for (int i = 0; i < Bin.size(); i++) {
		Bin[i].setSize(sf::Vector2f(64, 64));
		Bin[i].setTexture(&TrashTexture);

	}

	Bin[0].setPosition((43 * 64), (1 * 64)); // med room 1 cabinet
	Bin[1].setPosition((43 * 64), (8 * 64)); // med room 2 cabinet
	Bin[2].setPosition((40 * 64), (23 * 64)); // warden room cabinet 1
	Bin[3].setPosition((40 * 64), (25 * 64)); // visitation
	Bin[4].setPosition((30 * 64), (25 * 64)); // visitation 2

	Bin[5].setPosition((43 * 64), (53 * 64)); // cabinet 1 operating room
	Bin[6].setPosition((1 * 64), (27 * 64)); // cabinet 2 operating room
	Bin[7].setPosition((14 * 64), (27 * 64)); // cabinet 3 operating room
	
	Bin[8].setPosition((13 * 64), (7 * 64)); // bin cellblock
	Bin[9].setPosition((18 * 64), (7 * 64)); // bin cellblock
	Bin[10].setPosition((23 * 64), (7 * 64)); // bin cellblock
	

	for (int i = 0; i < Bin.size(); i++) {
		window.draw(Bin[i]);
	}


	std::vector<sf::RectangleShape>  Shower(7, sf::RectangleShape(showerHead)); // an array of 5 cell doorsa

	for (int i = 0; i < Shower.size(); i++) {
		Shower[i].setSize(sf::Vector2f(64, 64));
		Shower[i].setTexture(&showerTexture);

	}

	Shower[0].setPosition((1 * 64), (1 * 64));
	Shower[1].setPosition((1 * 64), (4 * 64));
	Shower[2].setPosition((1 * 64), (7 * 64));
	Shower[3].setPosition((1 * 64), (10 * 64));
	Shower[4].setPosition((1 * 64), (13 * 64));
	Shower[5].setPosition((1 * 64), (16 * 64));
	Shower[6].setPosition((1 * 64), (19 * 64));

	for (int i = 0; i < Shower.size(); i++) {
		window.draw(Shower[i]);
	}

	std::vector<sf::RectangleShape>  Washing(2, sf::RectangleShape(WashingMachine)); // an array of 5 cell doorsa

	for (int i = 0; i < Washing.size(); i++) {
		Washing[i].setSize(sf::Vector2f(64, 64));
		Washing[i].setTexture(&WashingTexture);

	}

	Washing[0].setPosition((26 * 64), (49 * 64)); 
	Washing[1].setPosition((27 * 64), (49 * 64)); 
	

	for (int i = 0; i < Washing.size(); i++) {
		window.draw(Washing[i]);
	}

	std::vector<sf::RectangleShape>  Basket(2, sf::RectangleShape(LaundryBasket)); // an array of 5 cell doorsa

	for (int i = 0; i < Basket.size(); i++) {
		Basket[i].setSize(sf::Vector2f(64, 64));
		Basket[i].setTexture(&LBasketTexture);

	}

	Basket[0].setPosition((29 * 64), (53 * 64)); 
	Basket[1].setPosition((30 * 64), (53 * 64)); 


	for (int i = 0; i < Basket.size(); i++) {
		window.draw(Basket[i]);
	}

	std::vector<sf::RectangleShape>  ManHole(7, sf::RectangleShape(DrainPipe)); // an array

	for (int i = 0; i < ManHole.size(); i++) {
		ManHole[i].setSize(sf::Vector2f(64, 64));
		ManHole[i].setTexture(&DrainTexture);

	}

	ManHole[0].setPosition((3 * 64), (1 * 64));
	ManHole[1].setPosition((3 * 64), (4 * 64));
	ManHole[2].setPosition((3 * 64), (7 * 64));
	ManHole[3].setPosition((3 * 64), (10 * 64));
	ManHole[4].setPosition((3 * 64), (13 * 64));
	ManHole[5].setPosition((3 * 64), (16 * 64));
	ManHole[6].setPosition((3 * 64), (19 * 64));

	for (int i = 0; i < ManHole.size(); i++) {
		window.draw(ManHole[i]);
	}

	std::vector<sf::RectangleShape>  Phone(4, sf::RectangleShape(PayPhone)); // an array 


	for (int i = 0; i < Phone.size(); i++) {
		Phone[i].setSize(sf::Vector2f(64, 64));
		Phone[i].setTexture(&PhoneTexture);

	}

	Phone[0].setPosition((17 * 64), (16 * 64));
	Phone[1].setPosition((20 * 64), (16 * 64));
	Phone[2].setPosition((23 * 64), (16 * 64));
	Phone[3].setPosition((26 * 64), (16 * 64));



	for (int i = 0; i < Phone.size(); i++) {
		window.draw(Phone[i]);
	}
	

}

void Furniture::mediumFurniture(sf::RenderWindow &window) {
	if (!DeskTexture.loadFromFile("../assets/image_assets/OfficeDesk.png")) {
		std::cout << "Load fail Error on cellTexture" << std::endl;
		system("pause");

	}

	if (!TVTexture.loadFromFile("../assets/image_assets/TV.png")) {
		std::cout << "Load fail Error on cellTexture" << std::endl;
		system("pause");

	}

	if (!SofaTexture.loadFromFile("../assets/image_assets/Sofa.png")) {
		std::cout << "Load fail Error on cellTexture" << std::endl;
		system("pause");

	}

	if (!FtLockerTexture.loadFromFile("../assets/image_assets/Footlocker.png")) {
		std::cout << "Load fail Error on cellTexture" << std::endl;
		system("pause");

	}

	if (!bedTexture.loadFromFile("../assets/image_assets/prisonBed.png")) {
		std::cout << "Load fail Error on cellTexture" << std::endl;
		system("pause");

	}

	if (!medbedTexture.loadFromFile("../assets/image_assets/MedicalBed.png")) {
		std::cout << "Load fail Error on cellTexture" << std::endl;
		system("pause");

	}

	if (!MopTexture.loadFromFile("../assets/image_assets/MopAndBucket.png")) {
		std::cout << "Load fail Error on cellTexture" << std::endl;
		system("pause");

	}

	if (!BookTexture.loadFromFile("../assets/image_assets/Bookshelf.png")) {
		std::cout << "Load fail Error on cellTexture" << std::endl;
		system("pause");

	}

	if (!MicrowaveTexture.loadFromFile("../assets/image_assets/MicrowaveAndKettle.png")) {
		std::cout << "Load fail Error on cellTexture" << std::endl;
		system("pause");

	}

	std::vector<sf::RectangleShape>  MicroWave(2, sf::RectangleShape(MicrowaveKettle)); // an array of 5 cell doorsa

	for (int i = 0; i < MicroWave.size(); i++) {
		MicroWave[i].setSize(sf::Vector2f(128, 64));
		MicroWave[i].setTexture(&MicrowaveTexture);

	}

	MicroWave[0].setPosition((27 * 64), (7 * 64)); //left of cellblock

	MicroWave[1].setPosition((29 * 64), (7 * 64));//right of cellblock




	for (int i = 0; i < MicroWave.size(); i++) {
		window.draw(MicroWave[i]);
	}


	std::vector<sf::RectangleShape>  Television(2, sf::RectangleShape(cbTV)); // an array of 5 cell doorsa

	for (int i = 0; i < Television.size(); i++) {
		Television[i].setSize(sf::Vector2f(128, 64));
		Television[i].setTexture(&TVTexture);

	}

	Television[0].setPosition((10 * 64), (19 * 64)); //left of cellblock

	Television[1].setPosition((30 * 64), (16 * 64));//right of cellblock




	for (int i = 0; i < Television.size(); i++) {
		window.draw(Television[i]);
	}



	std::vector<sf::RectangleShape>  Bench(4, sf::RectangleShape(sofa)); // an array of 5 cell doorsa

	for (int i = 0; i < Bench.size(); i++) {
		Bench[i].setSize(sf::Vector2f(128, 64));
		Bench[i].setTexture(&SofaTexture);

	}

	Bench[0].setPosition((9 * 64), (17 * 64)); //left of cellblock
	Bench[1].setPosition((11 * 64), (17 * 64));//left of cellblock


	Bench[2].setPosition((29 * 64), (14 * 64));//right of cellblock
	Bench[3].setPosition((31 * 64), (14 * 64));//right of cellblock
	


	for (int i = 0; i < Bench.size(); i++) {
		window.draw(Bench[i]);
	}

	std::vector<sf::RectangleShape>  ftLocker(5, sf::RectangleShape(footlocker)); // an array of 5 cell doorsa

	for (int i = 0; i < ftLocker.size(); i++) {
		ftLocker[i].setSize(sf::Vector2f(128, 64));
		ftLocker[i].setTexture(&FtLockerTexture);

	}

	ftLocker[0].setPosition((10 * 64), (1 * 64));
	ftLocker[1].setPosition((15 * 64), (1 * 64));
	ftLocker[2].setPosition((20 * 64), (1 * 64));
	ftLocker[3].setPosition((25 * 64), (1 * 64));
	ftLocker[4].setPosition((30 * 64), (1 * 64));


	for (int i = 0; i < ftLocker.size(); i++) {
		window.draw(ftLocker[i]);
	}
	


	std::vector<sf::RectangleShape>  PrisonerBed(11, sf::RectangleShape(prisonBed)); // an array of 5 cell doorsa

	for (int i = 0; i < PrisonerBed.size(); i++) {
		PrisonerBed[i].setSize(sf::Vector2f(64, 128));
		PrisonerBed[i].setTexture(&bedTexture);

	}

	PrisonerBed[0].setPosition((9 * 64), (1 * 64));
	PrisonerBed[1].setPosition((14 * 64), (1 * 64));
	PrisonerBed[2].setPosition((19 * 64), (1 * 64));
	PrisonerBed[3].setPosition((24 * 64), (1 * 64));
	PrisonerBed[4].setPosition((29 * 64), (1 * 64));

	PrisonerBed[5].setPosition((1 * 64), (66 * 64));
	PrisonerBed[6].setPosition((5 * 64), (66 * 64));
	PrisonerBed[7].setPosition((9 * 64), (66 * 64));
	PrisonerBed[8].setPosition((13 * 64), (66 * 64));
	PrisonerBed[9].setPosition((17 * 64), (66 * 64));
	PrisonerBed[10].setPosition((21 * 64), (66 * 64));

	for (int i = 0; i < PrisonerBed.size(); i++) {
		window.draw(PrisonerBed[i]);
	}

	std::vector<sf::RectangleShape>  MedBed(4, sf::RectangleShape(medicalBed)); // an array of 5 cell doorsa

	for (int i = 0; i < MedBed.size(); i++) {
		MedBed[i].setSize(sf::Vector2f(128, 128));
		MedBed[i].setTexture(&medbedTexture);

	}

	MedBed[0].setPosition((42 * 64), (3 * 64));
	MedBed[1].setPosition((42 * 64), (5 * 64));
	MedBed[2].setPosition((42 * 64), (10 * 64));
	MedBed[3].setPosition((42 * 64), (12 * 64));
	

	for (int i = 0; i < MedBed.size(); i++) {
		window.draw(MedBed[i]);
	}

	std::vector<sf::RectangleShape>  Desk(7, sf::RectangleShape(officeDesk)); // an array of 5 cell doorsa

	for (int i = 0; i < Desk.size(); i++) {
		Desk[i].setSize(sf::Vector2f(128, 64));
		Desk[i].setTexture(&DeskTexture);

	}

	Desk[0].setPosition((38 * 64), (1 * 64)); // med room 1 desk
	Desk[1].setPosition((38 * 64), (8 * 64)); // med room 2 desk
	Desk[2].setPosition((38 * 64), (15 * 64)); // warden room desk 1
	Desk[3].setPosition((42 * 64), (15 * 64)); // warden room desk 2
	Desk[4].setPosition((40 * 64), (49 * 64)); // desk 1 operating room
	Desk[5].setPosition((36 * 64), (49 * 64)); // desk 2 operating room
	Desk[6].setPosition((32 * 64), (49 * 64)); // desk 3 operating room
	

	for (int i = 0; i < Desk.size(); i++) {
		window.draw(Desk[i]);
	}


	std::vector<sf::RectangleShape>  MopNBuck(2, sf::RectangleShape(MopAndBucket)); // an array of 5 cell doorsa

	for (int i = 0; i < MopNBuck.size(); i++) {
		MopNBuck[i].setSize(sf::Vector2f(64, 128));
		MopNBuck[i].setTexture(&MopTexture);

	}

	MopNBuck[0].setPosition((16 * 64), (30 * 64));
	MopNBuck[1].setPosition((16 * 64), (27 * 64));
	

	for (int i = 0; i < MopNBuck.size(); i++) {
		window.draw(MopNBuck[i]);
	}

	
	std::vector<sf::RectangleShape>  Book(16, sf::RectangleShape(Bookshelf)); // an array of 5 cell doorsa

	for (int i = 0; i < Book.size(); i++) {
		Book[i].setSize(sf::Vector2f(128, 54));
		Book[i].setTexture(&BookTexture);

	}

	Book[0].setPosition((41 * 64), (61 * 64)); // far right
	Book[1].setPosition((41 * 64), (63 * 64));
	Book[2].setPosition((41 * 64), (65 * 64));
	Book[3].setPosition((41 * 64), (67 * 64));

	Book[4].setPosition((39 * 64), (61 * 64)); // second to furthest
	Book[5].setPosition((39 * 64), (63 * 64));
	Book[6].setPosition((39 * 64), (65 * 64));
	Book[7].setPosition((39 * 64), (67 * 64));

	Book[8].setPosition((35 * 64), (61 * 64)); //second most left
	Book[9].setPosition((35 * 64), (63 * 64));
	Book[10].setPosition((35 * 64), (65 * 64));
	Book[11].setPosition((35 * 64), (67 * 64));

	Book[12].setPosition((33 * 64), (61 * 64)); // most left of library
	Book[13].setPosition((33 * 64), (63 * 64));
	Book[14].setPosition((33 * 64), (65 * 64));
	Book[15].setPosition((33 * 64), (67 * 64));

	for (int i = 0; i < Book.size(); i++) {
		window.draw(Book[i]);
	}
	
	
	
}

void Furniture::largeFurniture(sf::RenderWindow &window) {
	


	if (!ServTexture.loadFromFile("../assets/image_assets/ServingTable.png")) {
		std::cout << "Load fail Error on cellTexture" << std::endl;
		system("pause");

	}

	if (!TableTexture.loadFromFile("../assets/image_assets/CafeteriaTable.png")) {
		std::cout << "Load fail Error on cellTexture" << std::endl;
		system("pause");

	}

	if (!BenchTexture.loadFromFile("../assets/image_assets/CafeteriaBench.png")) {
		std::cout << "Load fail Error on cellTexture" << std::endl;
		system("pause");

	}

	if (!VisitTexture.loadFromFile("../assets/image_assets/VisitorsTable.png")) {
		std::cout << "Load fail Error on cellTexture" << std::endl;
		system("pause");

	}

	if (!WardenTexture.loadFromFile("../assets/image_assets/WardenDesk.png")) {
		std::cout << "Load fail Error on cellTexture" << std::endl;
		system("pause");

	}
	

	sf::RectangleShape(WardDesk);
	WardDesk.setSize(sf::Vector2f(192, 192));
	WardDesk.setTexture(&WardenTexture);
	WardDesk.setPosition((41 * 64), (18 * 64));
	window.draw(WardDesk);


	std::vector<sf::RectangleShape>  PrisonBench(8, sf::RectangleShape(CafBench)); // an array of 5 cell doorsa

	for (int i = 0; i < PrisonBench.size(); i++) {
		PrisonBench[i].setSize(sf::Vector2f(320, 64));
		PrisonBench[i].setTexture(&BenchTexture);

	}

	PrisonBench[0].setPosition((3 * 64), (29 * 64)); //cafeteria
	PrisonBench[1].setPosition((8 * 64), (29 * 64));//cafeteria
	PrisonBench[2].setPosition((3 * 64), (32 * 64));//cafeteria
	PrisonBench[3].setPosition((8 * 64), (32 * 64));//cafeteria

	PrisonBench[4].setPosition((11 * 64), (10 * 64)); // cellblock
	PrisonBench[5].setPosition((11 * 64), (13 * 64));// cellblock

	PrisonBench[6].setPosition((19 * 64), (10 * 64)); // cellblock
	PrisonBench[7].setPosition((19 * 64), (13 * 64));// cellblock

	for (int i = 0; i < PrisonBench.size(); i++) {
		window.draw(PrisonBench[i]);
	}

	std::vector<sf::RectangleShape>  PrisonTable(4, sf::RectangleShape(CafTable)); // an array of 5 cell doorsa

	for (int i = 0; i < PrisonTable.size(); i++) {
		PrisonTable[i].setSize(sf::Vector2f(320, 128));
		PrisonTable[i].setTexture(&TableTexture);

	}

	PrisonTable[0].setPosition((3 * 64), (30 * 64));// table in cafeteria to the left
	PrisonTable[1].setPosition((8 * 64), (30 * 64)); // table in cafeteria to the right
	
	PrisonTable[2].setPosition((11 * 64), (11 * 64)); // table in cellblock
	PrisonTable[3].setPosition((19 * 64), (11 * 64)); // table in cellblock

	for (int i = 0; i < PrisonTable.size(); i++) {
		window.draw(PrisonTable[i]);
	}

	std::vector<sf::RectangleShape>  PrisonServing(2, sf::RectangleShape(ServTable)); // an array of 5 cell doorsa

	for (int i = 0; i < PrisonServing.size(); i++) {
		PrisonServing[i].setSize(sf::Vector2f(320, 128));
		PrisonServing[i].setTexture(&ServTexture);

	}

	PrisonServing[0].setPosition((3 * 64), (25 * 64));//cafeteria
	PrisonServing[1].setPosition((8 * 64), (25 * 64));//cafeteria


	for (int i = 0; i < PrisonServing.size(); i++) {
		window.draw(PrisonServing[i]);
	}

	
	std::vector<sf::RectangleShape>  VisitationTable(3, sf::RectangleShape(Visitation)); // an array of 5 cell doorsa

	for (int i = 0; i < VisitationTable.size(); i++) {
		VisitationTable[i].setSize(sf::Vector2f(192, 192));
		VisitationTable[i].setTexture(&VisitTexture);

	}

	VisitationTable[0].setPosition((35 * 64), (25 * 64));//cafeteria
	VisitationTable[1].setPosition((35 * 64), (28 * 64));//cafeteria
	VisitationTable[2].setPosition((35 * 64), (31 * 64));//cafeteria

	for (int i = 0; i < VisitationTable.size(); i++) {
		window.draw(VisitationTable[i]);
	}




}

void Furniture::WorkShop(sf::RenderWindow &window) {
	if (!WorkBenchTexture.loadFromFile("../assets/image_assets/WorkBench.png")) {
		std::cout << "Load fail Error on cellTexture" << std::endl;
		system("pause");

	}
	if (!SanderTexture.loadFromFile("../assets/image_assets/Sander.png")) {
		std::cout << "Load fail Error on cellTexture" << std::endl;
		system("pause");

	}
	if (!ToolsCabinetTexture.loadFromFile("../assets/image_assets/ToolsCabinet.png")) {
		std::cout << "Load fail Error on cellTexture" << std::endl;
		system("pause");

	}
	if (!DumpsterTexture.loadFromFile("../assets/image_assets/Dumpster.png")) {
		std::cout << "Load fail Error on cellTexture" << std::endl;
		system("pause");

	}
	if (!TimberTexture.loadFromFile("../assets/image_assets/TimberStorage.png")) {
		std::cout << "Load fail Error on cellTexture" << std::endl;
		system("pause");

	}
	if (!JigSawTexture.loadFromFile("../assets/image_assets/JigSaw.png")) {
		std::cout << "Load fail Error on cellTexture" << std::endl;
		system("pause");

	}

//	sf::RectangleShape WorkBench, Sander, ToolsCabinet, Dumpster, TimberStorage, JigSaw;
	std::vector<sf::RectangleShape>  WorkShopBench(2, sf::RectangleShape(WorkBench)); // an array of 5 cell doorsa

	for (int i = 0; i < WorkShopBench.size(); i++) {
		WorkShopBench[i].setSize(sf::Vector2f(128, 128));
		WorkShopBench[i].setTexture(&WorkBenchTexture);

	}

	WorkShopBench[0].setPosition((26 * 64), (42 * 64)); //cafeteria
	WorkShopBench[1].setPosition((26 * 64), (45 * 64));//cafeteria
	


	for (int i = 0; i < WorkShopBench.size(); i++) {
		window.draw(WorkShopBench[i]);
	}

	std::vector<sf::RectangleShape>  ToolCabin(2, sf::RectangleShape(ToolsCabinet)); // an array of 5 cell doorsa

	for (int i = 0; i < ToolCabin.size(); i++) {
		ToolCabin[i].setSize(sf::Vector2f(128, 128));
		ToolCabin[i].setTexture(&ToolsCabinetTexture);

	}

	ToolCabin[0].setPosition((28 * 64), (39 * 64)); //cafeteria
	ToolCabin[1].setPosition((30 * 64), (39 * 64));//cafeteria



	for (int i = 0; i < ToolCabin.size(); i++) {
		window.draw(ToolCabin[i]);
	}

	std::vector<sf::RectangleShape>  Sand(2, sf::RectangleShape(Sander)); // an array of 5 cell doorsa

	for (int i = 0; i < Sand.size(); i++) {
		Sand[i].setSize(sf::Vector2f(128, 128));
		Sand[i].setTexture(&SanderTexture);

	}

	Sand[0].setPosition((32 * 64), (39 * 64)); //cafeteria
	Sand[1].setPosition((35 * 64), (39 * 64));//cafeteria



	for (int i = 0; i < Sand.size(); i++) {
		window.draw(Sand[i]);
	}

	std::vector<sf::RectangleShape>  Dump(2, sf::RectangleShape(Dumpster)); // an array of 5 cell doorsa

	for (int i = 0; i < Dump.size(); i++) {
		Dump[i].setSize(sf::Vector2f(128, 128));
		Dump[i].setTexture(&DumpsterTexture);

	}

	Dump[0].setPosition((36 * 64), (46 * 64)); //cafeteria
	Dump[1].setPosition((32 * 64), (46 * 64));//cafeteria



	for (int i = 0; i < Dump.size(); i++) {
		window.draw(Dump[i]);
	}

	std::vector<sf::RectangleShape>  Saw(2, sf::RectangleShape(JigSaw)); // an array of 5 cell doorsa

	for (int i = 0; i < Saw.size(); i++) {
		Saw[i].setSize(sf::Vector2f(128, 128));
		Saw[i].setTexture(&JigSawTexture);

	}

	Saw[0].setPosition((42 * 64), (39 * 64)); //cafeteria
	Saw[1].setPosition((38 * 64), (39 * 64));//cafeteria



	for (int i = 0; i < Saw.size(); i++) {
		window.draw(Saw[i]);
	}

	sf::RectangleShape(TimberStorage);
	TimberStorage.setSize(sf::Vector2f(256, 256));
	TimberStorage.setTexture(&TimberTexture);
	TimberStorage.setPosition((40 * 64), (44 * 64));
	window.draw(TimberStorage);

}