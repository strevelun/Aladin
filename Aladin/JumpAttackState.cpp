#include "JumpAttackState.h"
#include "Player.h"

void JumpAttackState::Update(Player* player, float deltaTime)
{
	player->UpdateStateIdx(6);

	if (player->GetCurStateIdx() >= 5)
		player->ChangeState(STATE::JUMP);

	if (GetAsyncKeyState('A') & 0x8000)
	{
		player->SetDir(DIR::LEFT);
		player->MoveXPos(deltaTime, 1000);
	}
	if (GetAsyncKeyState('D') & 0x8000)
	{
		player->SetDir(DIR::RIGHT);
		player->MoveXPos(deltaTime, 1000);
	}



	player->Jump(false, deltaTime);
}