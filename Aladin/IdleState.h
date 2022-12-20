#pragma once
#include "PlayerState.h"

class IdleState :
    public PlayerState
{
public:

    void Update(Player* player, float deltaTime);
};

