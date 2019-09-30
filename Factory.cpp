
#include "Factory.h"
#include "Unit.h"
#include <vector>
#include <string>
#include <fstream>
#include <algorithm>
#include <iostream>
Factory::Factory(const Cell& cell,Player& player):cell(cell), player(player)
{
	std::cout << "Factory::Factory(Cell)" << std::endl;
}
Player& Factory::getPlayer() const
{
	return player;
}
 const Cell* Factory::getFactoryCell() const
{
	const Cell* c = & cell;
	return c;
}
Factory::~Factory()
{
	std::cout << "Factory::~Factory()" << std::endl;
	std::for_each(departments.begin(), departments.end(), [](Factory* factory) { delete factory; });
}
Unit* Factory::getUnit(const std::string& unitType)
{
	Unit* unit = nullptr;
	std::vector<Factory*>::iterator iter = departments.begin();
	while (unit == nullptr && iter != departments.end())
	{
		unit = (*iter)->getUnit(unitType);
		++iter;
	}
	
	return unit;
}
std::string Factory::toString() const
{
	//std::string str = std::to_string(getFactoryCell()->getCellPositionx) + "," + std::to_string(getFactoryCell()->getCellPositiony);
	//std::cout << "GOFbj toString() "<< str << std::endl;
	return 0;
}