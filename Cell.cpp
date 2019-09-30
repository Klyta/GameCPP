#include "Cell.h"
#include <string>
Point::Point(int x, int y) : x(x),y(y)
{
}
Cell::Cell(std::string Type, Point point2) :LandScapeT(Type), point(point2)
{
}
const std::string Cell::getCellType() const
{
	return  LandScapeT;
}
int Cell::getCellPositionx() const
{
	return point.y;
}
int Cell::getCellPositiony() const
{
	return point.x;
}
void Cell::getOllData() const
{
	getCellPositionx();
	getCellPositiony();
	getCellType();
}
Cell::~Cell()
{
}
