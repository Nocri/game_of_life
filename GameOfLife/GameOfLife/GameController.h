#pragma once
#include "GameEngine.h"
#include "ConsoleView.h"

#include <ctime>
#include <iostream> //Todo delete me
#include <string>
class GameController
{
	GameEngine *mEngine;
	View *mView;
	std::clock_t start;

public:
	GameController();
	GameController(int, int, std::string);
	~GameController();

	void play() {
	
	while (true) {
		long elapsedTime = clock() - start;
		if (elapsedTime / CLOCKS_PER_SEC > 1) {
			system("cls");
			std::string tempMap;
			(*mEngine).evaluate();

			//for each (std::vector<bool> line in (*mEngine).evaluate()){
			//	for each (bool dot in line) {
			//		std::cout << dot;
			//		tempMap.append(dot ? "O" : "X");
			//	}
			//	tempMap.append("\n");
			//}
			//std::cout << tempMap;
			start = clock();
		}
	}
	};
};

