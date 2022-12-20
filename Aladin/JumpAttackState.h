#pragma once
#include "PlayerState.h"

class JumpAttackState
	: public PlayerState
{
public:
	void Update(Player* player, float deltaTime);
};