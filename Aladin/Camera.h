#pragma once

#include <Windows.h>

class Background;


class Camera
{
private:
	int m_xpos = 0, m_ypos = 0, m_width, m_height;
	int m_backgroundWidth, m_backgroundHeight;

	Background* m_background;

public:
	Camera(int screenWidth, int screenHeight, Background* _background);
	~Camera();

	void MoveCamera(int _playerXPos, int _playerYPos, int _move);
	void Render(HDC _hdc);
	int GetXPos() const { return m_xpos; }
};