#include "GameController.h"



GameController::GameController()
{
	mEngine = new GameEngine();
	mView = new ConsoleView();
}


GameController::~GameController()
{
}
