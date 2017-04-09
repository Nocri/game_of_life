#pragma once
#include "View.h"
#include <iostream>
class ConsoleView :
	public View
{
public:
	ConsoleView();
	~ConsoleView();

	void showMap(std::vector<std::vector<bool>> map) {
		for (int i = 0; i < map.at(0).size(); i++) {
			for (int j = 0; j < map.size(); j++) {
				std::cout << (map[i][j] == true ? "O" : "X");
			}
			std::cout << "\n";
		}
	};
	void setMap(std::vector<std::vector<bool>> &map) {
		char move;
		int curX = 0, curY = 0;
		do {
			for (int i = 0; i < map.at(0).size(); i++) {
				for (int j = 0; j < map.size(); j++) {
					if (i == curY && j == curX) {
						std::cout << (map.at(i).at(j) == true? "|O|" : "|X|");
					}
					else {
						std::cout << (map[i][j] == true ? " O " : " X ");
					}
				}
				std::cout << "\n";
			}
			std::cin >> move;
			switch (move)
			{
			case 'w':
				if (curY != 0) {
					curY--;
				}
				break;
			case 's':
				if (curY != (map.size()-1)) {
					curY++;
				}
				break;
			case 'a':
				if (curX != 0) {
					curX--;
				}
				break;
			case 'd':
				if (curX != (map.at(0).size() - 1)) {
					curX++;
				}
				break;
			case 'o':
				map.at(curY).at(curX) = true;
				break;
			case 'k':
				map.at(curY).at(curX) = false;
				break;
			default:
				break;
			}

			system("cls");
		} while (move != 'q');
		
	};
};

                                    