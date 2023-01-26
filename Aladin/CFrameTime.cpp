#include "CFrameTime.h"
#include <cstdio>

CFrameTime* CFrameTime::m_inst = nullptr;

CFrameTime::CFrameTime()
{
	m_tick = timeGetTime();
}

CFrameTime::~CFrameTime()
{
}

bool CFrameTime::Update()
{
	DWORD tick = timeGetTime();

	m_deltaTime = (float)(tick - m_tick) / 1000;
	m_time += m_deltaTime;
	m_tick = tick;

	m_elapsedTime += m_deltaTime;
	if (m_frameLimit > 0)
		if (m_time < (1.0f / m_frameLimit))
		{
			/*
#ifdef _DEBUG
			char str[20] = "";
			sprintf_s(str, "%d\n", m_frame);
			OutputDebugStringA(str);
#endif
*/
			return false; // frameLimit ���� 1�� ������ 1�� �ȿ� frameLimit�� ��ŭ�� ������ ������
		}



	m_time = 0;
	m_frame++;


	if (m_elapsedTime >= 1.0f)
	{
		m_fps = m_frame / m_elapsedTime;
		m_frame = 0;
		m_elapsedTime = 0;
	}

	return true;
}
