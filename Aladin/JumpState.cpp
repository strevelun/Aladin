#include "JumpState.h"
#include "Player.h"

// 점프 중 이동 -> RunJump
// 점프 중 공격 -> AttackJump
void JumpState::Update(Player* player, float deltaTime)
{
	player->UpdateStateIdx(5);

	// 방향키 누르면 RunJumpState로 전환
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
