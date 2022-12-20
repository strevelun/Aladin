#include "FallState.h"
#include "Player.h"

void FallState::Update(Player* player, float deltaTime)
{
	player->UpdateStateIdx(5);

	if (GetAsyncKeyState('A') & 0x8000)
	{
		player->SetDir(DIR::LEFT);
		player->MoveXPos(deltaTime, 1);
	}
	else if (GetAsyncKeyState('D') & 0x8000)
	{
		player->SetDir(DIR::RIGHT);
		player->MoveXPos(deltaTime, 1);
	}
	else
	{
		player->Jump(false, deltaTime);
		return;
	}

	player->Jump(true, deltaTime);
}