#pragma once

#include "CSprite.h"
#include "Animation.h"
#include "Camera.h"

class PlayerState;
// RUNNING + JUMP : 0110
// RUNNING + INAIR : 1010
// IDLE	+ JUMP = 0101
// IDLE + INAIR = 1001

enum STATE
{
	IDLE, 
	RUNNING,
	JUMP, 
	INAIR, 
	FALL,
	ATTACK,
	RunJump,
	RunFall,
	JumpAttack,
	STATE_MAX
};

enum DIR
{
	LEFT,
	RIGHT
};

class Player
{
	// 월드 상에서의 좌표
	float m_xpos=100, m_ypos=650;
	
	float m_screenXPos = 100, m_screenYPos = 650;

	CBitmap* m_bitmap;
	//CSprite* m_curSprite;

	PlayerState* m_stateList[STATE_MAX];
	PlayerState* m_curState;

	STATE	m_state;
	DIR		m_dir;
	int m_curStateIdx = 0;
	float m_tick = 0;

	int m_jump = 18000; // 점프 높이
	int m_jumpStartYPos = 0; // 스페이스바 누를때 Ypos
	float m_jumpRate = -1.0f; 

	int m_moveSpeed = 10000;
	bool m_attack = false;

	CAnimation* m_anim[10];
	Camera* m_camera;

public:
	Player();
	Player(HWND hWnd);
	~Player();

	int GetCurStateIdx() const { return m_curStateIdx; }
	int GetXPos() const { return m_xpos; }
	int GetYPos() const { return m_ypos; }
	void MoveXPos(float deltaTime, int _speed = 5000);
	//STATE GetState() const { return m_state; }
	int GetMoveSpeed() const { return m_moveSpeed; }
	CBitmap* GetBitmap() const { return m_bitmap; }

	void SetCamera(Camera* _camera) { m_camera = _camera; }

	void UpdateStateIdx(int limit){ 
		m_curStateIdx = ++m_curStateIdx % limit;
	}	
	void SetDir(DIR dir) { m_dir = dir; }
	void ChangeState(STATE state) 
	{
		if (state != m_state)
		{
			m_curState = m_stateList[state];
			m_anim[m_state]->SetIdx(0);
			m_state = state;
			m_curStateIdx = -1;
		}
	}

	void Jump(bool _isRunning, float _deltaTime);

	void Input(float deltaTime);
	void Update(float deltaTime);
	void Render(HDC hdc, float deltaTime);

};

