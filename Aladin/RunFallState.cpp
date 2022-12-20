#include "RunFallState.h"
#include "Player.h"

void RunFallState::Update(Player* player, float deltaTime)
{
	player->UpdateStateIdx(5);

	if (GetAsyncKeyState('A') & 0x8000)
	{
		player->SetDir(DIR::LEFT);
		player->MoveXPos(deltaTime);
		player->ChangeState(STATE::RunFall);
	}
	else if (GetAsyncKeyState('D') & 0x8000)
	{
		player->SetDir(DIR::RIGHT);
		player->MoveXPos(deltaTime);
		player->ChangeState(STATE::RunFall);
	}
	else
	{
		player->Jump(false, deltaTime);
		return;
	}

	player->Jump(true, deltaTime);
}