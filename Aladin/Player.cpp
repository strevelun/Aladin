#include "Player.h"

Player::Player() {}

Player::Player(HWND hWnd)
{
	{
		m_idleSprites = new CSprite[7];
		m_idleSprites[0] = CSprite(6, 9, 37, 49);
		m_idleSprites[1] = CSprite(54, 12, 41, 46);
		m_idleSprites[2] = CSprite(106, 7, 40, 51);
		m_idleSprites[3] = CSprite(156, 4, 44, 54);
		m_idleSprites[4] = CSprite(205, 8, 41, 50);
		m_idleSprites[5] = CSprite(253, 8, 42, 50);
		m_idleSprites[6] = CSprite(301, 6, 44, 52);
	}

	{
		m_runningSprites = new CSprite[11];
		m_runningSprites[0]	 = CSprite(120, 1220, 41, 52);
		m_runningSprites[1]	 = CSprite(171, 1216, 40, 56);
		m_runningSprites[2]	 = CSprite(220, 1216, 52, 56);
		m_runningSprites[3]	 = CSprite(279, 1219, 45, 53);
		m_runningSprites[4]	 = CSprite(334, 1215, 42, 57);
		m_runningSprites[5]	 = CSprite(386, 1221, 40, 51);
		m_runningSprites[6]	 = CSprite(440, 1219, 35, 53);
		m_runningSprites[7]	 = CSprite(488, 1216, 49, 56);
		m_runningSprites[8]	 = CSprite(547, 1215, 55, 57);
		m_runningSprites[9]	 = CSprite(611, 1219, 55, 54);
		m_runningSprites[10] = CSprite(679, 1218, 45, 56);
	} 

	{
		m_jumpSprites = new CSprite[5];
		m_jumpSprites[0] = CSprite(8, 846, 59, 42);
		m_jumpSprites[1] = CSprite(75, 828, 52, 61);
		m_jumpSprites[2] = CSprite(137, 829, 54, 60);
		m_jumpSprites[3] = CSprite(203, 824, 54, 68);
		m_jumpSprites[4] = CSprite(269, 820, 51, 73);
	}

	{
		m_fallSprites = new CSprite[5];
		m_fallSprites[0] = CSprite(336, 829, 38, 65);
		m_fallSprites[1] = CSprite(390, 818, 35, 78);
		m_fallSprites[2] = CSprite(448, 808, 34, 92);
		m_fallSprites[3] = CSprite(504, 810, 34, 92);
		m_fallSprites[4] = CSprite(564, 812, 34, 92);
	}

	{
		m_runJumpSprites = new CSprite[5];
		m_runJumpSprites[0] = CSprite(10, 705, 41, 41);
		m_runJumpSprites[1] = CSprite(66, 683, 45, 75);
		m_runJumpSprites[2] = CSprite(124, 686, 57, 56);
		m_runJumpSprites[3] = CSprite(199, 698, 58, 41);
		m_runJumpSprites[4] = CSprite(273, 696, 60, 47);
	}

	{
		m_runFallSprites = new CSprite[5];
		m_runFallSprites[0] = CSprite(273, 696, 60, 47);
		m_runFallSprites[1] = CSprite(350, 692, 57, 52);
		m_runFallSprites[2] = CSprite(419, 688, 53, 57);
		m_runFallSprites[3] = CSprite(491, 680, 50, 84);
		m_runFallSprites[4] = CSprite(560, 719, 59, 43);
	}

	m_state = IDLE;
	
	m_bitmap = new CBitmap(hWnd, L"character.bmp");
	m_bitmap->AddSprite(m_idleSprites, "Idle");
	m_bitmap->AddSprite(m_runningSprites, "Running");
	m_bitmap->AddSprite(m_jumpSprites, "Jump");
	m_bitmap->AddSprite(m_fallSprites, "Fall");
	m_bitmap->AddSprite(m_runJumpSprites, "RunJump");
	m_bitmap->AddSprite(m_runFallSprites, "RunFall");
}

Player::~Player()
{
	delete[] m_idleSprites;
	delete[] m_runningSprites;
	delete[] m_jumpSprites;
	delete[] m_fallSprites;
	delete m_bitmap;
}

void Player::Input(float deltaTime)
{
	int temp = IDLE;

	if (GetAsyncKeyState('A') & 0x8000)
	{
		temp = RUNNING;
		m_dir = DIR::LEFT;
	}
	else if (GetAsyncKeyState('D') & 0x8000)
	{
		temp = RUNNING;
		m_dir = DIR::RIGHT;
	}
	

	// 현재 JUMP상태이면(1프레임 전에 JUMP키를 누른 상태이면) INAIR로 바로 교체함.
	if ((m_state & JUMP) != 0)
	{
		temp |= INAIR;
	}
	// 스페이스바 누를 시점에서 INAIR와 FALL인 상태가 아니어야 점프 가능
	else if ((GetAsyncKeyState(VK_SPACE) & 0x8000) && ((m_state & INAIR) == 0) && ((m_state & FALL) == 0))
	{
		temp |= JUMP;
	}
	// 현재 INAIR상태이면 계속 INAIR 상태로 
	else if ((m_state & INAIR) != 0)
	{
		temp |= INAIR;
	}

	// 현재 점프 최고점에 도달한 이후라면 INAIR가 아닌 FALL 상태로 전환
	if (m_jumpRate > 0.0f)
	{
		temp &= ~INAIR;
		temp |= FALL;
	}

	if (temp != m_state)
	{
		m_curStateIdx = 0;
		m_state = temp;
	}
}

void Player::Update(float deltaTime, bool backgroundLocked)
{
	if ((m_state & INAIR) != 0 || (m_state & FALL) != 0)
	{
		m_ypos += m_jump * deltaTime * m_jumpRate;

		m_jumpRate += 2.0f * deltaTime;

		if (m_ypos >= m_jumpStartYPos)
		{
			m_ypos = m_jumpStartYPos;
			m_state &= ~JUMP; // 점프 상태만 뺸다.
			m_jumpRate = -1.0f;
		}
	}

	if ((m_state & JUMP) != 0)
	{
		//m_jumpYpos = m_ypos - m_jump;
		// 점프할 시점에 yPos를 저장해둔다.
		m_jumpStartYPos = m_ypos;
	}

	if ((m_state & RUNNING) != 0 )
	{
		if (m_dir == DIR::LEFT)
		{
			m_xpos -= m_moveSpeed * deltaTime;

			if (!backgroundLocked)
			{
				m_screenXPos -= m_moveSpeed * deltaTime;
			}
		}
		else if (m_dir == DIR::RIGHT)
		{
			m_xpos += m_moveSpeed * deltaTime;

			if (!backgroundLocked)
			{
				m_screenXPos += m_moveSpeed * deltaTime;
			}
		}
	}

	m_tick += deltaTime;

	if (m_tick >= 0.1) // 값이 클수록 애니메이션이 느려짐
	{
		m_tick = 0;

		if ((m_state & IDLE) != 0)
		{
			if (m_state == IDLE)
				m_curStateIdx = ++m_curStateIdx % 7;
			if ((m_state & INAIR) != 0 || (m_state & JUMP) != 0)
				m_curStateIdx = ++m_curStateIdx % 5;
			else if ((m_state & FALL) != 0)
				m_curStateIdx = ++m_curStateIdx % 5;
		}

		if ((m_state & RUNNING) != 0)
		{
			if (m_state == RUNNING)
				m_curStateIdx = ++m_curStateIdx % 11;
			else if ((m_state & INAIR) != 0 || (m_state & JUMP) != 0)
				m_curStateIdx = ++m_curStateIdx % 5;
			else if ((m_state & FALL) != 0)
				m_curStateIdx = ++m_curStateIdx % 5;
		}
	}
}

void Player::Render(HDC hdc, float deltaTime)
{
	if ((m_state & IDLE) != 0)
	{
		if(m_state == IDLE)
			m_bitmap->RenderSprite(hdc, m_screenXPos, m_ypos, "Idle", m_curStateIdx);
		if ((m_state & INAIR) != 0 || (m_state & JUMP) != 0)
			m_bitmap->RenderSprite(hdc, m_screenXPos, m_ypos, "Jump", m_curStateIdx);
		else if ((m_state & FALL) != 0)
			m_bitmap->RenderSprite(hdc, m_screenXPos, m_ypos, "Fall", m_curStateIdx);
	}

	if ((m_state & RUNNING) != 0)
	{
		if (m_state == RUNNING)
			m_bitmap->RenderSprite(hdc, m_screenXPos, m_ypos, "Running", m_curStateIdx);
		else if ((m_state & INAIR) != 0 || (m_state & JUMP) != 0)
			m_bitmap->RenderSprite(hdc, m_screenXPos, m_ypos, "RunJump", m_curStateIdx);
		else if ((m_state & FALL) != 0)
			m_bitmap->RenderSprite(hdc, m_screenXPos, m_ypos, "RunFall", m_curStateIdx);
	}
}
