
#pragma once 

#include "CSprite.h"

class CBitmap;

// animation clip 
class CAnimation
{
private :
	//sprite ต้
	//	loop 
	//  frame size 

	CSprite** m_spriteList;
	int m_capacity;
	int m_size;
	int m_curIdx;
	bool m_loop;
	bool m_end;

	int m_delay = 0;
	int m_count = 0;

	CSprite* m_curSprite;


public :
	CAnimation(int _size, bool _loop = false);
	~CAnimation();
	void Add(CSprite* sprite);
	void Update(float _deltaTime);
	void Render(HDC _dest, float _sx, float _sy, HDC _memDC);
	void SetIdx(int _idx) { m_curIdx = _idx; }

	bool IsEnd() 
	{
		return m_curIdx >= m_capacity - 1;
	}
};





