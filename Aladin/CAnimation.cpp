#include "CAnimation.h"
#include "CBitmap.h"
#include "Player.h"
#include "CFrameTime.h"

CAnimation::CAnimation(int _capacity, bool _loop)
	: m_capacity(_capacity), m_size(0), m_curIdx(0), m_loop(_loop),
		m_end(false)
{
	m_spriteList = new CSprite*[_capacity];

}

CAnimation::~CAnimation()
{
	if( m_spriteList) delete[] m_spriteList;
}

void CAnimation::Add(CSprite* sprite)
{
	if (m_size >= m_capacity)
		return;
	m_spriteList[m_size++] = sprite;
	if(m_size == 1)
		m_curSprite = m_spriteList[0];
}

void CAnimation::Update(float _deltaTime)
{
	// 

	m_delay = CFrameTime::GetInstance()->GetFps() / m_capacity;
	m_count++;

	if (m_count >= m_delay)
	{
		m_curSprite = m_spriteList[m_curIdx];

		if (m_loop)
			m_curIdx = (m_curIdx + 1) % m_capacity;
		else
		{
			m_curIdx = (m_curIdx + 1);
			if (m_curIdx >= m_capacity - 1)
			{
				m_curIdx = m_capacity - 1;
				return;
			}
		}
		m_count = 0;
	}
}

void CAnimation::Render( HDC _dest , float _sx, float _sy, HDC _memDC)
{
	m_curSprite->Render(_dest, _sx, _sy, _memDC);
}