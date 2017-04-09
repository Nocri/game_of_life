#pragma once
#include <vector>
#include <string>
class GameEngine
{

	std::vector<std::vector<bool>> map;
	int minLiving, minReproducing, minDying;

public:
	GameEngine();
	GameEngine(int, int, std::string);
	~GameEngine();

	std::vector<std::vector<bool>> evaluate();
	std::vector<std::vector<bool>> getMap();
	int checkNeighbor(int, int, std::vector<std::vector<bool>>);
};

