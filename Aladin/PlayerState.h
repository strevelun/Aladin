#pragma once

//#include "Player.h"
class Player;

class PlayerState
{
public:
	virtual void Update(Player* player, float deltaTime) = 0;

};

