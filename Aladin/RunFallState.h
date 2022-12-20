#pragma once

#include "PlayerState.h"

class RunFallState :
	public PlayerState
{
public:
	void Update(Player* player, float deltaTime);
};