#include "JumpAttackState.h"
#include "Player.h"

void JumpAttackState::Update(Player* player, float deltaTime)
{
	player->UpdateStateIdx(6);


}