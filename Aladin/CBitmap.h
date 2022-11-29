 #pragma once

#include <Windows.h>

class CSprite;

class CBitmap
{
	HBITMAP			m_bitmap;
	HANDLE			m_hFile;
	LPDWORD			m_pixels = 0;
	HDC				m_hMemDC;
	HWND			m_hWnd;
	LPCWSTR			m_fileName;

	long			m_width = 0, m_height = 0;

	CSprite* m_sprites;

public:
	CBitmap() {}
	CBitmap(HWND hWnd, LPCWSTR fileName);

	int GetWidth() const { return m_width; }
	int GetHeight() const { return m_height; }
	void SetHwnd(HWND hWnd) { m_hWnd = hWnd; }
	void SetImage(LPCWSTR fileName) { m_fileName = fileName; }

	void RenderBit(HDC hdc);
	void RenderStretch(HDC hdc, long dx, long dy, int screenSizeX, int screenSizeY, float multiple);
	void RenderSprite(HDC hdc, int x, int y, int idx);
};