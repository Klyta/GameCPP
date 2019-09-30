#include"Unit.h"
#include"Cell.h"
#include<iostream>
#include<string>
#include<fstream>
#include "LandScape.h"
#include "Bonus.h"
int& Unit::getHealth()
{
	return(Health);
}
//int Unit::setHealth(int& H)
//{
//}
std::string Unit::toString()
{
	std::string str = std::to_string(getHealth()) +";"+  std::to_string(getDemage());
	std::cout << "GOUbj toString() " << str<< std::endl;
	return str;

}
void Unit::setHealth(int &health)
{
	Unit::Health = health;
}
void Unit::setDemage(int& demage)
{
	Unit::Demage = demage;
}

void Unit::unitLoad()
{
	std::ifstream ou;
	ou.open("Output.txt");
	if (ou.is_open())
	{
		std::cout << "Ok!" << std::endl;
	}
	else
	{
		std::cout << "Something wrong!" << std::endl;
	}
	std::string str;
	ou >> str;
	std::cout <<"Is - "<< str << std::endl;
	ou.close();
}

int& Unit::getDemage()
{
	return(Demage);
}
 Player& Unit::getPlayer() const
{
	return player;
}


Unit:: Unit(int Health, int Demage, const Cell* cell,Player& player) :Health(Health), Demage(Demage), cell(cell),player(player)
{
	std::cout << "Unit(int,int)" << std::endl;
}

Unit::~Unit()
{
	std::cout << "~Unit()" << std::endl;
}

void Unit::getAttackBonus()
{
	std::map <std::string, int> Bonus = getMap();
	int Dem = getDemage();
	const std::string Type = cell->getCellType();
	if (Type == "forest")
	{

		Dem = Dem + Bonus["forest"];
		setDemage(Dem);
	}
	if (Type == "pound")
	{
		Dem = Dem + Bonus["pound"];
		setDemage(Dem);
	}
}
void Unit::setDeaf()
{
	Deaf = 1;
}
bool Unit::getDeaf()
{
	std::cout << Deaf << std::endl;
	return Deaf;
}
const Cell* Unit::getUnitCell()
{
	return cell;
}
void Unit::move(Cell* cellM)
{
	cell = cellM;
	std::cout << "Move to - " << cellM->getCellPositionx()<<","<< cellM->getCellPositiony() << std::endl;
}
void Unit::attack(Unit& unitD)
{

	getAttackBonus();
	if (unitD.Deaf != 0)
	{
		Demage -= 20;
	}
	std::cout << unitD.Health << "\n" << Demage << std::endl;
	unitD.Health = unitD.Health - Demage;
	if (unitD.Health < 0 || unitD.Health == 0)
	{
		(&unitD)->~Unit();
		std::cout << "Dead" << std::endl;
	}
	std::cout << unitD.Health << std::endl;
}
std::string Unit::getUnit_type()
{
	return unit_type;

}