 #pragma once

#include <Windows.h>
#include <unordered_map>

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

	std::unordered_map<const char*, CSprite*> m_mapSprites;

public:
	CBitmap() {}
	CBitmap(HWND hWnd, LPCWSTR fileName);

	int GetWidth() const { return m_width; }
	int GetHeight() const { return m_height; }
	void SetHwnd(HWND hWnd) { m_hWnd = hWnd; }
	void SetImage(LPCWSTR fileName) { m_fileName = fileName; }
	void AddSprite(CSprite* sprite, const char* name) { m_mapSprites.insert(std::make_pair(name, sprite)); }

	void RenderBit(HDC hdc);
	void RenderStretch(HDC hdc, long sx, long xy, int screenSizeX, int screenSizeY, int dx, int dy, float multiple);
	void RenderSprite(HDC hdc, int x, int y, const char* name, int idx);
};