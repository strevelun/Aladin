#pragma once

#include "CSprite.h"

// RUNNING + JUMP : 0110
// RUNNING + INAIR : 1010
// IDLE	+ JUMP = 0101
// IDLE + INAIR = 1001

enum STATE
{
	IDLE = 1, // 0001 
	RUNNING = 2, // 0010
	JUMP = 4, // 0100
	INAIR = 8, // 1000
	FALL = 16, // 10000
};

enum DIR
{
	LEFT,
	RIGHT
};

class Player
{
	int m_xpos=200, m_ypos=500;
	CSprite* m_idleSprites;
	CSprite* m_runningSprites;
	CSprite* m_jumpSprites;
	CSprite* m_fallSprites;
	CSprite* m_runJumpSprites;
	CSprite* m_runFallSprites;
	CBitmap* m_bitmap;

	int	m_state;
	DIR		m_dir;
	int m_curStateIdx = 0;
	float m_tick = 0;

	int m_jumpYpos = -1;
	int m_jump =500;
	int m_jumpStartYPos = 0;
	float m_jumpSpeed = -1.0f; // 0¿Ã µ«∏È 

public:
	Player();
	Player(HWND hWnd);
	~Player();

	int GetCurStateIdx() const { return m_curStateIdx; }
	int GetXPos() const { return m_xpos; }
	int GetYPos() const { return m_ypos; }
	//STATE GetState() const { return m_state; }

	void Input(float deltaTime);
	void Update(float deltaTime);
	void Render(HDC hdc, float deltaTime);
};

