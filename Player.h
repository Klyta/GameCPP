#pragma once
#include <string>
#include "GameObj.h"
class Player
{
   std::stack<GameObj*>  playerObj;
public:
	void SaveGame() const;
	void Save(GameObj* obj) ;
};

