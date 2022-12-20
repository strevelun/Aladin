#include "AttackState.h"
#include "Player.h"


void AttackState::Update(Player* player, float deltaTime)
{
	player->UpdateStateIdx(5);

	if (player->GetCurStateIdx() >= 4)
		player->ChangeState(STATE::IDLE);
}