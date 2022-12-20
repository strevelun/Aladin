#pragma once

#include "PlayerState.h"

class RunJumpState 
	: public PlayerState
{
private:

public:
	void Update(Player* player, float deltaTime);
};