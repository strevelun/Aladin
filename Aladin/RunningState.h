#pragma once
#include "PlayerState.h"
class RunningState :
    public PlayerState
{
public:
    void Update(Player* player, float deltaTime);


};

