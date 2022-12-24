
#pragma once 

// animation clip 
//class CSprite;
#include "CSprite.h"

class CBitmap;

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

	CSprite* m_curSprite;


public :
	CAnimation(int _size, bool _loop = false);
	~CAnimation();
	void Add(CSprite* sprite);
	void Update();
	void Render(HDC _dest, float _sx, float _sy, HDC _memDC);
	void SetIdx(int _idx) { m_curIdx = _idx; }

	bool IsEnd() 
	{
		return m_curIdx >= m_capacity - 1;
	}
};


// Animation idleAni = new Animation(3) ;
// idleAni->Add( sprite1  ) ;
// idleAni->Add( sprite2  ) ;
// idleAni->Add( sprite3  ) ;





