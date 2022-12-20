#pragma
#include "PlayerState.h"

class FallState :
	public PlayerState
{
private:

public:
	void Update(Player* player, float deltaTime);
};