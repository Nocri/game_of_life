#pragma once
#include "GameEngine.h"
#include "ConsoleView.h"

class GameController
{
	GameEngine *mEngine;
	View *mView;

public:
	GameController();
	~GameController();
};

