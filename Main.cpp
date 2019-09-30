#include"Unit.h"
#include "Cavalry.h"
#include"Cell.h"
#include<iostream>
#include"Builder.h"
#include "CavalryFactory.h"
#include "vector"
#include <exception>

int main()
{
	try
	{
		Point p1(0, 0);
		Point p2(0, 1);
		Point p3(0, 2);
		Point p4(0, 3);
		Cell cell1("forest",p1);
		Cell cell2("pound",p2);
		Cell cell3("forest",p3);
		Cell cell4("forest", p4);
		Player player1;
		Player player2;
		Builder builder1(100, 10, &cell3, player1);
		Builder builder2(100, 10, &cell3, player2);
		CavalryFactory* cavalryFactory1 = builder1.bildFactory();
		CavalryFactory* cavalryFactory2 = builder2.bildFactory();
		Cavalry *cavalry1= cavalryFactory1->getUnit("cavalry");
		Cavalry *cavalry2 = cavalryFactory2->getUnit("cavalry");
		cavalry1->attack(*cavalry2);
		cavalry2->attack(*cavalry1);
		cavalry1->attack(*cavalry2);
		cavalry1->move(&cell4);
		//player1.Save(cavalry1);
		player1.SaveGame();
		delete cavalry1;
		std::cout << "delete c1   " << std::endl;
		delete cavalryFactory1;
		std::cout << "delete cf1   " << std::endl;
	}
	catch (const std::exception& ex)
	{
		std::cout << ex.what() << std::endl;
	}
	catch (...)
	{
		std::cout << "Something wrong" << std::endl;
	}
}