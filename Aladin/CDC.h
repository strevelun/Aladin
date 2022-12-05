#pragma once

#include <Windows.h>

class CBitmap;

class CDC
{
	CBitmap* m_bitmap;

public:
	CDC() {}
	CDC(CBitmap* bitmap);
	void SetBitmap(CBitmap* bitmap) { m_bitmap = bitmap; }

	void Render(HDC hdc);
	void Render(HDC hdc, long dx, long dy, float multiple);
	void RenderScreen(HDC hdc, int x, int y, int screenSizeX, int screenSizeY, int dx, int dy);
	//void RenderSprite(HDC hdc, int x, int y, int idx);
};