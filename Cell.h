#pragma once
#include <string>
#include <vector>
struct Point
{
	int x= 5;
	int y = 5;
	Point(int,int);
};
class Cell
{
	Point point;

	 std::string LandScapeT;
public:
	const std::string getCellType() const;
	int getCellPositionx() const;
	int getCellPositiony() const;
	Cell(std::string,Point);
	void getOllData() const;
	~Cell();
};