#include "Player.h"
#include "IdleState.h"
#include "RunningState.h"
#include "JumpState.h"
#include "PlayerState.h"
#include "FallState.h"
#include "RunJumpState.h"
#include "RunFallState.h"
#include "AttackState.h"
#include "JumpAttackState.h"

Player::Player() {}

Player::Player(HWND hWnd)
{
	/*
	CSprite* m_spriteList = new CSprite[5];
	m_spriteList[0] = CSprite(8, 846, 59, 42);
	m_spriteList[1] = CSprite(75, 828, 52, 61);
	m_spriteList[2] = CSprite(137, 829, 54, 60);
	m_spriteList[3] = CSprite(203, 824, 54, 68);
	m_spriteList[4] = CSprite(269, 820, 51, 73);




	{
		m_jumpAttackSprites = new CSprite[6];
		m_jumpAttackSprites[0] = CSprite(13, 1077, 52, 53);
		m_jumpAttackSprites[1] = CSprite(75, 1075, 50, 51);
		m_jumpAttackSprites[2] = CSprite(140, 1067, 46, 65);
		m_jumpAttackSprites[3] = CSprite(199, 1078, 51, 55);
		m_jumpAttackSprites[4] = CSprite(266, 1070, 82, 59);
		m_jumpAttackSprites[5] = CSprite(361, 1087, 58, 54);
	}

	*/
	m_stateList[STATE::IDLE] = new IdleState();
	m_curState = m_stateList[STATE::IDLE];
	m_curStateIdx = STATE::IDLE;

	m_anim[STATE::IDLE] = new CAnimation(7, true);
	m_anim[STATE::IDLE]->Add(new CSprite(6, 9, 37, 49));
	m_anim[STATE::IDLE]->Add(new CSprite(54, 12, 41, 46));
	m_anim[STATE::IDLE]->Add(new CSprite(106, 7, 40, 51));
	m_anim[STATE::IDLE]->Add(new CSprite(156, 4, 44, 54));
	m_anim[STATE::IDLE]->Add(new CSprite(205, 8, 41, 50));
	m_anim[STATE::IDLE]->Add(new CSprite(253, 8, 42, 50));
	m_anim[STATE::IDLE]->Add(new CSprite(301, 6, 44, 52));

	m_anim[STATE::RUNNING] = new CAnimation(11, true);
	m_anim[STATE::RUNNING]->Add(new CSprite(120, 1220, 41, 52));
	m_anim[STATE::RUNNING]->Add(new CSprite(171, 1216, 40, 56));
	m_anim[STATE::RUNNING]->Add(new CSprite(220, 1216, 52, 56));
	m_anim[STATE::RUNNING]->Add(new CSprite(279, 1219, 45, 53));
	m_anim[STATE::RUNNING]->Add(new CSprite(334, 1215, 42, 57));
	m_anim[STATE::RUNNING]->Add(new CSprite(386, 1221, 40, 51));
	m_anim[STATE::RUNNING]->Add(new CSprite(440, 1219, 35, 53));
	m_anim[STATE::RUNNING]->Add(new CSprite(488, 1216, 49, 56));
	m_anim[STATE::RUNNING]->Add(new CSprite(547, 1215, 55, 57));
	m_anim[STATE::RUNNING]->Add(new CSprite(611, 1219, 55, 54));
	m_anim[STATE::RUNNING]->Add(new CSprite(679, 1218, 45, 56));

	m_stateList[STATE::RUNNING] = new RunningState();

	m_anim[STATE::JUMP] = new CAnimation(5, false);
	m_anim[STATE::JUMP]->Add(new CSprite(8, 846, 59, 42));
	m_anim[STATE::JUMP]->Add(new CSprite(75, 828, 52, 61));
	m_anim[STATE::JUMP]->Add(new CSprite(137, 829, 54, 60));
	m_anim[STATE::JUMP]->Add(new CSprite(203, 824, 54, 68));
	m_anim[STATE::JUMP]->Add(new CSprite(269, 820, 51, 73));

	m_stateList[STATE::JUMP] = new JumpState();

	m_anim[STATE::FALL] = new CAnimation(5, false);
	m_anim[STATE::FALL]->Add(new CSprite(336, 829, 38, 65));
	m_anim[STATE::FALL]->Add(new CSprite(390, 818, 35, 78));
	m_anim[STATE::FALL]->Add(new CSprite(448, 808, 34, 92));
	m_anim[STATE::FALL]->Add(new CSprite(504, 810, 34, 92));
	m_anim[STATE::FALL]->Add(new CSprite(564, 812, 34, 92));

	m_stateList[STATE::FALL] = new FallState();

	m_anim[STATE::RunJump] = new CAnimation(5, false);
	m_anim[STATE::RunJump]->Add(new CSprite(10, 705, 41, 41));
	m_anim[STATE::RunJump]->Add(new CSprite(66, 683, 45, 75));
	m_anim[STATE::RunJump]->Add(new CSprite(124, 686, 57, 56));
	m_anim[STATE::RunJump]->Add(new CSprite(199, 698, 58, 41));
	m_anim[STATE::RunJump]->Add(new CSprite(273, 696, 60, 47));

	m_stateList[STATE::RunJump] = new RunJumpState();

	m_anim[STATE::RunFall] = new CAnimation(5, false);
	m_anim[STATE::RunFall]->Add(new CSprite(273, 696, 60, 47));
	m_anim[STATE::RunFall]->Add(new CSprite(350, 692, 57, 52));
	m_anim[STATE::RunFall]->Add(new CSprite(419, 688, 53, 57));
	m_anim[STATE::RunFall]->Add(new CSprite(491, 680, 50, 84));
	m_anim[STATE::RunFall]->Add(new CSprite(560, 719, 59, 43));

	m_stateList[STATE::RunFall] = new RunFallState();

	m_anim[STATE::ATTACK] = new CAnimation(5, false);
	m_anim[STATE::ATTACK]->Add(new CSprite(5, 337, 45, 50));
	m_anim[STATE::ATTACK]->Add(new CSprite(54, 326, 51, 61));
	m_anim[STATE::ATTACK]->Add(new CSprite(115, 314, 44, 73));
	m_anim[STATE::ATTACK]->Add(new CSprite(171, 319, 81, 68));
	m_anim[STATE::ATTACK]->Add(new CSprite(260, 335, 51, 52));
	m_stateList[STATE::ATTACK] = new AttackState();

	m_anim[STATE::JumpAttack] = new CAnimation(6, false);
	m_anim[STATE::JumpAttack]->Add(new CSprite(13, 1077, 52, 53));
	m_anim[STATE::JumpAttack]->Add(new CSprite(75, 1075, 50, 51));
	m_anim[STATE::JumpAttack]->Add(new CSprite(140, 1067, 46, 65));
	m_anim[STATE::JumpAttack]->Add(new CSprite(199, 1078, 51, 55));
	m_anim[STATE::JumpAttack]->Add(new CSprite(266, 1070, 82, 59));
	m_anim[STATE::JumpAttack]->Add(new CSprite(361, 1087, 58, 54));
	m_stateList[STATE::JumpAttack] = new JumpAttackState();

	m_state = STATE::IDLE;
	m_bitmap = new CBitmap(hWnd, L"character.bmp");

}

Player::~Player()
{

	for (int i = 0; i < STATE::STATE_MAX; i++)
		delete m_stateList[i];

	m_curState = nullptr;
}

void Player::MoveXPos(float deltaTime, int _speed)
{

	int camDir = 1;
	float temp = (_speed * deltaTime); // 0.013

	switch (m_dir)
	{
	case DIR::LEFT:
		m_xpos -= (_speed * deltaTime);
		camDir = -1;
		
		break;
	case DIR::RIGHT:
		m_xpos += (_speed * deltaTime);
		
		break;
	}

	m_camera->MoveCamera(m_xpos, m_ypos, camDir * _speed * deltaTime);
}

void Player::Jump(bool _isRunning, float _deltaTime)
{
	if (m_jumpRate <= -1.0f) // 점프 처음 시작할때
	{
		m_jumpStartYPos = m_ypos;
	}
	else if (m_jumpRate > 0.0f) // 최고점 도달
	{
		if (m_state != STATE::JumpAttack)
		{
			if (_isRunning)
				ChangeState(STATE::RunFall);
			else
				ChangeState(STATE::FALL);
		}
	}



	if (m_jumpRate < 1.0f)
	{
		m_ypos += m_jump * _deltaTime * m_jumpRate;

#ifdef _DEBUG
		char str[20] = "";
		sprintf_s(str, "%f\n", _deltaTime);
		OutputDebugStringA(str);
#endif

		m_jumpRate += 0.14f;
	}
	else // 착지
	{
		m_ypos = m_jumpStartYPos;
		m_jumpRate = -1.0f;
		
		if (_isRunning)
			ChangeState(STATE::RUNNING);
		else
			ChangeState(STATE::IDLE);
	}
	
}

void Player::Input(float deltaTime)
{
}

void Player::Update(float deltaTime)
{
	m_curState->Update(this, deltaTime);
	m_anim[m_state]->Update(deltaTime);
}

void Player::Render(HDC hdc, float deltaTime)
{
	// 현위치 - 카메라 위치
	m_anim[m_state]->Render(hdc, (m_xpos - m_camera->GetXPos()), m_ypos, m_bitmap->GetMemDC());
}
