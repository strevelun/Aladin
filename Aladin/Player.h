#pragma once

#include "CSprite.h"

enum STATE
{
	IDLE,
	RUNNING
};

enum DIR
{
	LEFT,
	RIGHT
};

class Player
{
	float m_xpos=200, m_ypos=500;
	CSprite* m_idleSprites;
	CSprite* m_runningSprites;
	CBitmap* m_bitmap;

	STATE	m_state;
	DIR		m_dir;
	int m_curStateIdx = 0;
	float m_tick = 0;

public:
	Player();
	Player(HWND hWnd);
	int GetCurStateIdx() const { return m_curStateIdx; }
	int GetXPos() const { return m_xpos; }
	int GetYPos() const { return m_ypos; }
	STATE GetState() const { return m_state; }

	void Input(float deltaTime);
	void Update(float deltaTime);
	void Render(HDC hdc, float deltaTime);
};

