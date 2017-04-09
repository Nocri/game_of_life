#include <iostream>
#include "GameController.h"


int main() {
	GameController *gc;

	int x, y;
	std::cin >> x >> y;

	gc = new GameController(x, y, "1/3/4");

	(*gc).play();

	system("pause");
	return 0;
}