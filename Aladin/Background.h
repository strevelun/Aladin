#pragma once

#include <Windows.h>

class CBitmap;

class Background
{
	CBitmap* m_bitmap;

public:
	Background(HWND hWnd);
	~Background();

	void Render(HDC hdc, int screenPosX, int screenPosY, int screenSizeX, int screenSizeY,
		int backPosX, int backPosY);
};

