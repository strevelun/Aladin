#include "RunningState.h"
#include "Player.h"

void RunningState::Update(Player* player, float deltaTime)
{
	player->UpdateStateIdx(11);


	if (GetAsyncKeyState('A') & 0x8000)
	{
		player->SetDir(DIR::LEFT);
		player->MoveXPos(deltaTime);
	}
	else if (GetAsyncKeyState('D') & 0x8000)
	{
		player->SetDir(DIR::RIGHT);
		player->MoveXPos(deltaTime);
	}
	else
		player->ChangeState(STATE::IDLE);
	
	if (GetAsyncKeyState('Q') & 0x8000)
	{
		player->ChangeState(STATE::ATTACK);
	}
	else if (GetAsyncKeyState(VK_SPACE) & 0x8000)
	{
		player->ChangeState(STATE::RunJump);
	}

	/*
		if (!backgroundLocked)
		{
			m_screenXPos -= m_moveSpeed * deltaTime;
		}
	
		if (!backgroundLocked)
		{
			m_screenXPos += m_moveSpeed * deltaTime;
		}
		*/
}
