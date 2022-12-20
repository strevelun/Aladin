#include "CDC.h"
#include "CBitmap.h"
#include <Windows.h>

CDC::CDC(CBitmap* bitmap)
{
	//m_bitmap = bitmap;
}

void CDC::Render(HDC hdc)
{
	//m_bitmap->RenderBit(hdc);
}

void CDC::Render(HDC hdc, long dx, long dy, float multiple)
{
	//m_bitmap->RenderStretch(hdc, dx, dy, multiple);
}

void CDC::RenderScreen(HDC hdc, int x, int y, int screenSizeX, int screenSizeY, int dx, int dy)
{
	//if (m_bitmap == nullptr)
	//	return;

	//m_bitmap->RenderStretch(hdc, x, y, screenSizeX, screenSizeY, dx, dy, 1);
}
/*
void CDC::RenderSprite(HDC hdc, int x, int y, int idx)
{
	if (m_bitmap == nullptr)
		return;

	m_bitmap->RenderSprite(hdc, x, y, idx);
}
*/
