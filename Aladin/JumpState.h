#pragma once
#include "PlayerState.h"
class JumpState :
    public PlayerState
{
public:
    void Update(Player* player, float deltaTime);
};

