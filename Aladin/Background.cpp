#include "Background.h"
#include "CBitmap.h"

Background::Background(HWND hWnd)
{
	m_bitmap = new CBitmap(hWnd, L"background.bmp");
}

Background::~Background()
{
	delete m_bitmap;
}

void Background::Render(HDC hdc, int screenPosX, int screenPosY, int screenSizeX, int screenSizeY,
	int backPosX, int backPosY)
{
	m_bitmap->RenderStretch(hdc, screenPosX, screenPosY, screenSizeX, screenSizeY, 
		backPosX, backPosY, 1/1.55f);
}
