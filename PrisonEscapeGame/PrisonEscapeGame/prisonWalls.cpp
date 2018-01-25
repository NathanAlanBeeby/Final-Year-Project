#include "prisonWalls.h"



prisonWalls::prisonWalls()
{
	leftOuterWall = 68;
	bottomOuterWall = 45;
	topOuterWall = 45;
	rightOuterSeg1 = 35;
	rightOuterSeg2 = 19;
	rightOuterSeg3 = 12;


	showerWall = 33;
	cellBigWall = 16;
	showerMidWall = 9;
	cellMediumWall = 6;
	cellSmallWall = 2;

	wallSize = 30;
	
}


prisonWalls::~prisonWalls()
{
}

void prisonWalls::outerWalls(sf::RenderWindow &window) {
	if (!wallTexture.loadFromFile("../assets/image_assets/wall.png")) {
		std::cout << "Load fail Error on wallTexture" << std::endl;
		system("pause");

	}

	//(rightOuterSeg1 + rightOuterSeg2 + rightOuterSeg3) +
	int wallCount = (rightOuterSeg1 + rightOuterSeg2 + rightOuterSeg3 + leftOuterWall + topOuterWall + bottomOuterWall);

	std::vector<sf::RectangleShape>  OutWalls(wallCount, sf::RectangleShape(wallBlock)); // an array of 5 cell doors

	for (int i = 0; i < OutWalls.size(); i++) {

		OutWalls[i].setSize(sf::Vector2f(64, 64));
		OutWalls[i].setTexture(&wallTexture);

	}

	//Top Outer Wall
	for (int i = 0; i < topOuterWall; i++) {
		OutWalls[i].setPosition((i * 64), 0);
		window.draw(OutWalls[i]);
	}
	//Bottom Outer Wall
	for (int j = 0; j < bottomOuterWall; j++) {
		OutWalls[j].setPosition((j * 64), (69 * 64));
		window.draw(OutWalls[j]);
	}
	//left outer wall
	for (int k = 0; k < leftOuterWall; k++) {
		OutWalls[k].setPosition(0, 64 + (k * 64));
		window.draw(OutWalls[k]);
	}
	//right outer segment top
	for (int l = 0; l < rightOuterSeg1; l++) {
		OutWalls[l].setPosition((44 * 64), 64 + (l * 64));
		window.draw(OutWalls[l]);
	}
	//right outer segment middle
	for (int m = 0; m < rightOuterSeg2; m++) {
		OutWalls[m].setPosition((44 * 64), (37 * 64) + (m * 64));
		window.draw(OutWalls[m]);
	}
	//right outer segment bottom
	for (int n = 0; n < rightOuterSeg3; n++) {
		OutWalls[n].setPosition((44 * 64), (57 * 64) + (n * 64));
		window.draw(OutWalls[n]);
	}
}

void prisonWalls::cellblockInnerWalls(sf::RenderWindow &window) {

	int wallSize = (showerWall + cellBigWall + showerMidWall + (cellMediumWall * 4) + (cellSmallWall * 5) + 5);

	std::vector<sf::RectangleShape>  inWalls(wallSize, sf::RectangleShape(wallBlock)); // an array of 5 cell doors
	//setting texture and size
	for (int i = 0; i < inWalls.size(); i++) {
		inWalls[i].setSize(sf::Vector2f(64, 64));
		inWalls[i].setTexture(&wallTexture);
	}
	


	//Top Outer Wall
	for (int i = 0; i < showerWall; i++) {
		inWalls[i].setPosition(64 + (i * 64), (20 * 64));
		window.draw(inWalls[i]);
	}
	for (int j = 0; j < cellBigWall; j++) {
		inWalls[j].setPosition((33 * 64), 64 + (j * 64));
		window.draw(inWalls[j]);
	}
	for (int k = 0; k < cellSmallWall; k++) {
		inWalls[k].setPosition((33 * 64), (18 * 64) + (k * 64));
		window.draw(inWalls[k]);
	}

	for (int l = 0; l < showerMidWall; l++) {
		inWalls[l].setPosition((8 * 64), 64 + (l * 64));
		window.draw(inWalls[l]);
	}
	for (int m = 0; m < showerMidWall; m++) {
		inWalls[m].setPosition((8 * 64), (11 * 64) + (m * 64));
		window.draw(inWalls[m]);
	}

	for (int i = 0; i < 4; i++) {
		for (int n = 0; n < cellMediumWall; n++) {
			inWalls[n].setPosition((13 * 64) + (i *(5 * 64)), 64 + (n * 64));
			window.draw(inWalls[n]);
		}
	}
	for (int i = 0; i < 5; i++) {
		for (int o = 0; o < cellSmallWall; o++) {
			inWalls[o].setPosition((9 * 64) + (i * (5 * 64)) + (o * 64), (6 * 64));
			window.draw(inWalls[o]);
		}
	}

	for (int p = 0; p < 5; p++) {
		
			inWalls[p].setPosition((12 * 64) + (p * (5 * 64)), (6 * 64));
			window.draw(inWalls[p]);
		
	}

}

void prisonWalls::medicalInnerWalls(sf::RenderWindow &window) {
	

	std::vector<sf::RectangleShape>  inWalls(wallSize, sf::RectangleShape(wallBlock)); // an array of 5 cell doors
																					   //setting texture and size
	for (int i = 0; i < inWalls.size(); i++) {
		inWalls[i].setSize(sf::Vector2f(64, 64));
		inWalls[i].setTexture(&wallTexture);
	}


	//bottom medical Walls
	for (int j = 0; j < 2; j++) {
		for (int i = 0; i < 6; i++) {
			inWalls[i].setPosition((38 * 64) + (i * 64), (7 * 64) + j *(7 * 64));
			window.draw(inWalls[i]);
		}
	}
	//top left wall
	for (int k = 0; k < 4; k++) {
		inWalls[k].setPosition((37 * 64),64 +(k * 64));
		window.draw(inWalls[k]);
	}
	//mid left wall
	for (int l = 0; l < 6; l++) {
		inWalls[l].setPosition((37 * 64), (6 * 64) + (l * 64));
		window.draw(inWalls[l]);
	}



}

void prisonWalls::closetAndCafInnerWalls(sf::RenderWindow &window) {
	caffeterianWallSize = 60;
	std::vector<sf::RectangleShape>  inWalls(caffeterianWallSize, sf::RectangleShape(wallBlock)); 
																					  
	for (int i = 0; i < inWalls.size(); i++) {
		inWalls[i].setSize(sf::Vector2f(64, 64));
		inWalls[i].setTexture(&wallTexture);
	}
	//cafe first top left block 
	for (int i = 0; i < 1; i++) {
		inWalls[i].setPosition((1 * 64), (24 * 64));
		window.draw(inWalls[i]);
	}
	//cafe bottom left block 
	for (int i = 0; i < 1; i++) {
		inWalls[i].setPosition((1 * 64), (34 * 64));
		window.draw(inWalls[i]);
	}
	//wall below closet
	for (int j = 0; j < 3; j++) {
		inWalls[j].setPosition((19 * 64) + (j * 64), (34 * 64));
		window.draw(inWalls[j]);
	}

	// wall below cafeteria
	for (int j = 0; j < 15; j++) {
		inWalls[j].setPosition((3 * 64) + (j * 64), (34 * 64));
		window.draw(inWalls[j]);
	}


	//wall middle of closet
	for (int j = 0; j < 5; j++) {
		inWalls[j].setPosition((16 * 64) + (j * 64), (29 * 64));
		window.draw(inWalls[j]);
	}


	// wall above food tray
	for (int j = 0; j < 10; j++) {
		inWalls[j].setPosition((3 * 64) + (j * 64), (24 * 64));
		window.draw(inWalls[j]);
	}
	//wall connecting cafe and closet
	for (int j = 0; j < 4; j++) {
		inWalls[j].setPosition((14 * 64) + (j * 64), (24 * 64));
		window.draw(inWalls[j]);
	}
	//wall top right on closet
	for (int j = 0; j < 3; j++) {
		inWalls[j].setPosition((19 * 64) + (j * 64), (24 * 64));
		window.draw(inWalls[j]);
	}
	//left wall of closets
	for (int j = 0; j < 9; j++) {
		inWalls[j].setPosition((15 * 64), (25 * 64) + (j * 64));
		window.draw(inWalls[j]);
	}
	for (int j = 0; j < 9; j++) {
		inWalls[j].setPosition((21 * 64), (25 * 64) + (j * 64));
		window.draw(inWalls[j]);
	}



}

void prisonWalls::wardenVisitationInnerWalls(sf::RenderWindow &window) {
	wardenWallSize = 56;
	std::vector<sf::RectangleShape>  inWalls(wardenWallSize, sf::RectangleShape(wallBlock)); // an array of 5 cell doors
																							 //setting texture and size
	for (int i = 0; i < inWalls.size(); i++) {
		inWalls[i].setSize(sf::Vector2f(64, 64));
		inWalls[i].setTexture(&wallTexture);
	}
	//wardens higher wall
	for (int i = 0; i < 7; i++) {
		inWalls[i].setPosition((37 * 64), (13 * 64) + (i * 64));
		window.draw(inWalls[i]);
	}
	// wardens lower wall
	for (int j = 0; j < 3; j++) {
		inWalls[j].setPosition((37 * 64), (21 * 64) + (j * 64));
		window.draw(inWalls[j]);
	}
	// top of visitation
	for (int k = 0; k < 19; k++) {
		inWalls[k].setPosition((25 * 64) + (k * 64), (24 * 64));
		window.draw(inWalls[k]);
	}

	//bottom of visitation
	for (int l = 0; l < 16; l++) {
		inWalls[l].setPosition((28 * 64) + (l * 64), (34 * 64));
		window.draw(inWalls[l]);
	}
	// top of visitation
	for (int m = 0; m < 10; m++) {
		inWalls[m].setPosition((25 * 64), (25 * 64) + (m * 64));
		window.draw(inWalls[m]);
	}
	// a for loop for one block because you know I regurgitated the same code for each wall
	for (int n = 0; n < 1; n++) {
		inWalls[n].setPosition((26 * 64), (34 * 64));
		window.draw(inWalls[n]);
	}
}

void prisonWalls::yardInnerWalls(sf::RenderWindow &window) {
	yardWallSize = 60;
	std::vector<sf::RectangleShape>  inWalls(yardWallSize, sf::RectangleShape(wallBlock));

	for (int i = 0; i < inWalls.size(); i++) {
		inWalls[i].setSize(sf::Vector2f(64, 64));
		inWalls[i].setTexture(&wallTexture);
	}
	//Yard first top left block 
	for (int i = 0; i < 1; i++) {
		inWalls[i].setPosition((1 * 64), (38 * 64));
		window.draw(inWalls[i]);
	}
	// yard top blocks
	for (int i = 0; i < 19; i++) {
		inWalls[i].setPosition((3 * 64) + (i * 64), (38 * 64));
		window.draw(inWalls[i]);
	}
	//yard right blocks
	for (int i = 0; i < 20; i++) {
		inWalls[i].setPosition((21 * 64), (39 * 64) + (i * 64));
		window.draw(inWalls[i]);
	}
	//yard right blocks
	for (int i = 0; i < 2; i++) {
		inWalls[i].setPosition((21 * 64), (60 * 64) + (i * 64));
		window.draw(inWalls[i]);
	}
	for (int i = 0; i < 1; i++) {
		inWalls[i].setPosition((1 * 64), (61 * 64));
		window.draw(inWalls[i]);
	}
	for (int i = 0; i < 18; i++) {
		inWalls[i].setPosition((3 * 64) + (i * 64), (61 * 64));
		window.draw(inWalls[i]);
	}
}

void prisonWalls::workLaundSecInnerWalls(sf::RenderWindow &window) {
	workInnerWallsSize = 73;
	std::vector<sf::RectangleShape>  inWalls(workInnerWallsSize, sf::RectangleShape(wallBlock));

	for (int i = 0; i < inWalls.size(); i++) {
		inWalls[i].setSize(sf::Vector2f(64, 64));
		inWalls[i].setTexture(&wallTexture);
	}
	//workshop first top left blocks 
	for (int i = 0; i < 2; i++) {
		inWalls[i].setPosition((25 * 64) + (i * 64), (38 * 64));
		window.draw(inWalls[i]);
	}

	//workshop top after door blocks 
	for (int i = 0; i < 16; i++) {
		inWalls[i].setPosition((28 * 64) + (i * 64), (38 * 64));
		window.draw(inWalls[i]);
	}
	//workshop bottom blocks
	for (int i = 0; i < 18; i++) {
		inWalls[i].setPosition((26 * 64) + (i * 64), (48 * 64));
		window.draw(inWalls[i]);
	}
	//workshop left blocks 
	for (int i = 0; i < 16; i++) {
		inWalls[i].setPosition((25 * 64), (39 * 64) + (i * 64));
		window.draw(inWalls[i]);
	}
	//laundry right hand blocks 
	for (int i = 0; i < 5; i++) {
		inWalls[i].setPosition((31 * 64), (49 * 64) + (i * 64));
		window.draw(inWalls[i]);
	}

	//  laundry bottom 1 block wall
	for (int i = 0; i < 1; i++) {
		inWalls[i].setPosition((26 * 64) , (54 * 64));
		window.draw(inWalls[i]);
	}

	//  laundry bottom 5 block wall
	for (int i = 0; i < 5; i++) {
		inWalls[i].setPosition((28 * 64) + (i * 64), (54 * 64));
		window.draw(inWalls[i]);
	}

	//  laundry bottom 1 block wall
	for (int i = 0; i < 10; i++) {
		inWalls[i].setPosition((34 * 64) + (i * 64), (54 * 64));
		window.draw(inWalls[i]);
	}
}

void prisonWalls::solitaryLibraryInnerWalls(sf::RenderWindow &window) {
	solInnerWallsSize = 60;
	std::vector<sf::RectangleShape>  inWalls(solInnerWallsSize, sf::RectangleShape(wallBlock));

	for (int i = 0; i < inWalls.size(); i++) {
		inWalls[i].setSize(sf::Vector2f(64, 64));
		inWalls[i].setTexture(&wallTexture);
	}
	//workshop first top left blocks 
	for (int i = 0; i < 1; i++) {
		inWalls[i].setPosition((1 * 64), (65 * 64));
		window.draw(inWalls[i]);
	}

	 // cell walls for solitary top blocks - find a way to loop through all of these positions to reduce code
		for (int j = 0; j < 3; j++) {
		inWalls[j].setPosition((3 * 64) + (j * 64), (65 * 64));
		window.draw(inWalls[j]);
		}

		for (int j = 0; j < 3; j++) {
			inWalls[j].setPosition((7 * 64) + (j * 64), (65 * 64));
			window.draw(inWalls[j]);
		}
		for (int j = 0; j < 3; j++) {
			inWalls[j].setPosition((11 * 64) + (j * 64), (65 * 64));
			window.draw(inWalls[j]);
		}
		for (int j = 0; j < 3; j++) {
			inWalls[j].setPosition((15 * 64) + (j * 64), (65 * 64));
			window.draw(inWalls[j]);
		}
		for (int j = 0; j < 3; j++) {
			inWalls[j].setPosition((19 * 64) + (j * 64), (65 * 64));
			window.draw(inWalls[j]);
		}
		for (int j = 0; j < 3; j++) {
			inWalls[j].setPosition((23 * 64) + (j * 64), (65 * 64));
			window.draw(inWalls[j]);
		}
		// solitary walls to the right
		for (int i = 0; i < 6; i++) {
			for (int j = 0; j < 3; j++) {
				inWalls[j].setPosition((4 * 64) + (i * (4 * 64)), (66 * 64) + (j * 64));
				window.draw(inWalls[j]);
			}
		}
		// blocks to left of library above solitary
		for (int j = 0; j < 6; j++) {
			inWalls[j].setPosition((25 * 64), (59 * 64) + (j * 64));
			window.draw(inWalls[j]);
		}
		// top 2 left blocks of library before door
		for (int j = 0; j < 2; j++) {
			inWalls[j].setPosition((25 * 64) + (j * 64), (58 * 64));
			window.draw(inWalls[j]);
		}
		//walls between 2 doors above library
		for (int j = 0; j < 15; j++) {
			inWalls[j].setPosition((27 * 64) + (j * 64), (58 * 64));
			window.draw(inWalls[j]);
		}
		// 1 block to right of library door
		for (int j = 0; j < 1; j++) {
			inWalls[j].setPosition((43 * 64), (58 * 64));
			window.draw(inWalls[j]);
		}

}