#pragma once
#include <string>
#include <vector>
class View
{
public:
	virtual void showMap(std::vector<std::vector<bool>> map) = 0;
	virtual void setMap(std::vector<std::vector<bool>> &map) = 0;
};

