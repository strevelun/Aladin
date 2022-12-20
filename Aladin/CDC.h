#pragma once

#include <Windows.h>

class CBitmap;

class CDC
{
	HDC m_hdc;

public:
	CDC() {}
	CDC(CBitmap* bitmap);


	void Render(HDC hdc);
	void Render(HDC hdc, long dx, long dy, float multiple);
	void RenderScreen(HDC hdc, int x, int y, int screenSizeX, int screenSizeY, int dx, int dy);
	//void RenderSprite(HDC hdc, int x, int y, int idx);
};