 #pragma once

#include <Windows.h>
#include <vector>

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

	std::vector<CSprite*> m_sprites;

public:
	CBitmap() {}
	CBitmap(HWND hWnd, LPCWSTR fileName);

	int GetWidth() const { return m_width; }
	int GetHeight() const { return m_height; }
	HDC GetMemDC() const { return m_hMemDC; }
	void SetHwnd(HWND hWnd) { m_hWnd = hWnd; }
	void SetImage(LPCWSTR fileName) { m_fileName = fileName; }
	void AddSprite(CSprite* sprite) { m_sprites.push_back(sprite); }

	void RenderBit(HDC hdc);
	void RenderStretch(HDC hdc, long sx, long xy, int screenSizeX, int screenSizeY, float dx, float dy, float multiple);
	void RenderSprite(HDC hdc, int x, int y, const char* name, int idx);
};