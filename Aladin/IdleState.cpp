#include "IdleState.h"
#include "Player.h"

void IdleState::Update(Player* player, float deltaTime)
{
	player->UpdateStateIdx(7);

	if (GetAsyncKeyState('A') & 0x8000)
	{
		player->ChangeState(STATE::RUNNING);
		player->SetDir(DIR::LEFT);
	}
	else if (GetAsyncKeyState('D') & 0x8000)
	{
		player->ChangeState(STATE::RUNNING);
		player->SetDir(DIR::RIGHT);
	}

	if (GetAsyncKeyState('Q') & 0x8000)
	{
		player->ChangeState(STATE::ATTACK);
	}
	else if (GetAsyncKeyState(VK_SPACE) & 0x8000)
	{
		player->ChangeState(STATE::JUMP);
	}
}