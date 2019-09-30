
#include "CavalryFactory.h"
#include "Cavalry.h"
#include "Unit.h"
#include "Player.h"
#include <string>
#include <iostream>
CavalryFactory::CavalryFactory(const Cell& cell, Player& player) : Factory(cell, player)
{
	std::cout << "CFactory::CFactory(Cell)" << std::endl;
}
CavalryFactory::~CavalryFactory()
{
	std::cout << "CFactory::~CFactory()" << std::endl;
}

Cavalry* CavalryFactory::getUnit(const std::string& unitType)
{
	if (unitType == "cavalry")
	{
		Cavalry* unit = new Cavalry(100, 40, getFactoryCell(),getPlayer());
		std::cout << "Cavalry::getUnit" << std::endl;
	    player.Save(unit);
		return unit;
	}
	else
	{
		return nullptr;
	}
}
