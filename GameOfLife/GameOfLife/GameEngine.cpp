#include "GameEngine.h"

#include <iostream>

GameEngine::GameEngine()
{
}

GameEngine::GameEngine(int x, int y, std::string rules) {
	int counter = 0;

	for (int i = 0; i < rules.size(); i++) {
		if (rules.at(i) != '/') {
			switch (counter) {
			case 0:
				minLiving =(rules.at(i) - '0');
				break;
			case 1:
				minReproducing = (rules.at(i) - '0');
				break;
			case 2:
				minDying = (rules.at(i) - '0');
				break;
			}
		}
		else
		{
			counter++;
		}
	}

	for (int i = 0; i < x; i++) {
		std::vector<bool> line;
		for (int j = 0; j < y; j++) {
			line.push_back((j+i)%2 == 0 ? false : true);
			//line.push_back(false);
		}
		(this->map).push_back(line);
	}
	std::cout << minLiving << " " << minReproducing << " " << minDying<< "\n";
};

std::vector<std::vector<bool>> GameEngine::getMap() {
	return map;
}

std::vector<std::vector<bool>> GameEngine::evaluate() {
	std::vector<std::vector<bool>> tMap(this->map);

	std::cout << "local map:\n";
	for each (std::vector<bool> line in this->map){
		for each (bool dot in line) {
			std::cout << dot;
		}
		std::cout << "\n";
	}

	std::cout << "temp map:\n";
	for each (std::vector<bool> line in tMap) {
		for each (bool dot in line) {
			std::cout << dot;
		}
		std::cout << "\n";
	}

	for (int i = 0; i < tMap.size(); i++) {
		for (int j = 0; j < tMap.at(0).size(); j++) {
			int neighbors = checkNeighbor(j, i, map);
			if (neighbors < minLiving) {
				tMap[i][j] = false;
			}
			else if (neighbors < minReproducing) {

			}
			else if(neighbors < minDying)
			{
				tMap[i][j] = true;
			}
			else {
				tMap[i][j] = false;
			}

		}
	}

		std::cout << "\n";

		std::cout << "temp map after:\n";
		for each (std::vector<bool> line in tMap) {
			for each (bool dot in line) {
				std::cout << dot;
			}
			std::cout << "\n";
		}
		/*
		for each (std::vector<bool> line in tMap) {
			for each (bool dot in line) {
				if (dot)
					std::cout << dot;
				else
					std::cout << "nic ";
			}
		}
	}*/
		map = tMap;

	return map;
};



int GameEngine::checkNeighbor(int x, int y, std::vector<std::vector<bool>> map) {
	int neighbors = 0;

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (i != 1 && j != 1) {
				if (map.at(y).at(x)) {
					neighbors++;
				}
			}
		}
	}

	return neighbors;
}

GameEngine::~GameEngine()
{
}
