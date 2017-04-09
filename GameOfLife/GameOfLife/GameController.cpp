#include "GameController.h"



GameController::GameController()
{
	mEngine = new GameEngine();
	mView = new ConsoleView();
	start = std::clock();
}

GameController::GameController(int x, int y, std::string rules) {
	mEngine = new GameEngine(x, y, rules);
	mView = new ConsoleView();
	start = std::clock();
	(*mView).setMap((*mEngine).getMap());
};


GameController::~GameController()
{
}
