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
		m_runningSprites[0] = CSprite(120, 1220, 41, 52);
		m_runningSprites[1] = CSprite(171, 1216, 40, 56);
		m_runningSprites[2] = CSprite(220, 1216, 52, 56);
		m_runningSprites[3] = CSprite(279, 1219, 45, 53);
		m_runningSprites[4] = CSprite(334, 1215, 42, 57);
		m_runningSprites[5] = CSprite(386, 1221, 40, 51);
		m_runningSprites[6] = CSprite(440, 1219, 35, 53);
		m_runningSprites[7] = CSprite(488, 1216, 49, 56);
		m_runningSprites[8] = CSprite(547, 1215, 55, 57);
		m_runningSprites[9] = CSprite(611, 1219, 55, 54);
		m_runningSprites[10] = CSprite(679, 1218, 45, 56);
	}

	m_state = IDLE;
	

	m_bitmap = new CBitmap(hWnd, L"character.bmp");
	m_bitmap->AddSprite(m_idleSprites, "Idle");
	m_bitmap->AddSprite(m_runningSprites, "Running");
}

void Player::Input(float deltaTime)
{
	STATE temp;

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
	else
	{
		temp = IDLE;
	}

	if (temp != m_state)
	{
		m_curStateIdx = 0;
		m_state = temp;
	}
}

void Player::Update(float deltaTime)
{
	if (m_state == RUNNING)
	{
		if (m_dir == DIR::LEFT)
		{
			m_xpos -= 300 * deltaTime;
		}
		else if (m_dir == DIR::RIGHT)
		{
			m_xpos += 300 * deltaTime;
		}
	}

	m_tick += deltaTime;

	if (m_tick >= 0.1)
	{
		m_tick = 0;

		if (m_state == IDLE)
		{
			m_curStateIdx = ++m_curStateIdx % 7;
		}
		else if (m_state == RUNNING)
		{
			m_curStateIdx = ++m_curStateIdx % 11;
		}
	}

}

void Player::Render(HDC hdc, float deltaTime)
{
	if (m_state == IDLE)
		m_bitmap->RenderSprite(hdc, m_xpos, m_ypos, "Idle", m_curStateIdx);
	else if (m_state == RUNNING)
		m_bitmap->RenderSprite(hdc, m_xpos, m_ypos, "Running", m_curStateIdx);

}
