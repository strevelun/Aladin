#include "JumpState.h"
#include "Player.h"

// ���� �� �̵� -> RunJump
// ���� �� ���� -> AttackJump
void JumpState::Update(Player* player, float deltaTime)
{
	player->UpdateStateIdx(5);

	// ����Ű ������ RunJumpState�� ��ȯ
	if (GetAsyncKeyState('A') & 0x8000)
	{
		player->SetDir(DIR::LEFT);
		player->MoveXPos(deltaTime, 1);
		//player->ChangeState(STATE::RunJump);
	}
	if (GetAsyncKeyState('D') & 0x8000)
	{
		player->SetDir(DIR::RIGHT);
		player->MoveXPos(deltaTime, 1);
		//player->ChangeState(STATE::RunJump);
	}
	//else 
	{
		//player->Jump(false, deltaTime);
		//return;
	}

	player->Jump(false, deltaTime);
}
