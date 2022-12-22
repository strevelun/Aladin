#include "FallState.h"
#include "Player.h"

void FallState::Update(Player* player, float deltaTime)
{
	player->UpdateStateIdx(5);

	if (GetAsyncKeyState('A') & 0x8000)
	{
		player->SetDir(DIR::LEFT);
		player->MoveXPos(deltaTime, 1000);
	}
	else if (GetAsyncKeyState('D') & 0x8000)
	{
		player->SetDir(DIR::RIGHT);
		player->MoveXPos(deltaTime, 1000);
	}

	player->Jump(false, deltaTime);

	if (GetAsyncKeyState('Q') & 0x8000)
	{
		player->ChangeState(STATE::JumpAttack);
	}
}