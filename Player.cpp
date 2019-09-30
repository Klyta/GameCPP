#include "Player.h"

void Player::SaveGame() const
{
	if (playerObj.empty())
	{
		std::cout << "Eror,steck is empty" << std::endl;
	}
	std::cout<<"Save - Game -"<<playerObj.top()->toString() <<std::endl;
}

void Player::Save(GameObj* obj)
{
	playerObj.push(obj);
}