#pragma once
#include "PlayerState.h"

class AttackState :
    public PlayerState
{
public:
    void Update(Player* player, float deltaTime);
};

