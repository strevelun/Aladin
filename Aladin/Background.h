#pragma once

#include <Windows.h>

class CBitmap;

class Background
{
	CBitmap* m_bitmap;

public:
	Background(HWND hWnd);
	~Background();

	CBitmap* GetBitmap() const { return m_bitmap; }

	void Render(HDC hdc, int screenPosX, int screenPosY, int screenSizeX, int screenSizeY,
		float backPosX, float backPosY);
};

