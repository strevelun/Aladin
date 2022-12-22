#include "JumpState.h"
#include "Player.h"

// ���� �� �̵� -> RunJump
// ���� �� ���� -> AttackJump
void JumpState::Update(Player* player, float deltaTime)
{
	player->UpdateStateIdx(5);

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

	if (GetAsyncKeyState('Q') & 0x8000)
	{
		player->ChangeState(STATE::JumpAttack);
	}

	player->Jump(false, deltaTime);
}
