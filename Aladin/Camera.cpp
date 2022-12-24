#include "Camera.h"
#include "Background.h"
#include "CBitmap.h"

Camera::Camera(int screenWidth, int screenHeight, Background* _background)
{
	m_width = screenWidth;
	m_height = screenHeight;
	m_backgroundWidth = _background->GetBitmap()->GetWidth();
	m_backgroundHeight = _background->GetBitmap()->GetHeight();

	m_background = _background;
}

Camera::~Camera()
{
}

void Camera::MoveCamera(int _playerXPos, int _playerYPos, int _move)
{
	// 카메라위치가 0인 경우에만 카메라 이동 x

	if (m_xpos + _move <= 0)
	{
		m_xpos = 0;
		return;
	}
	else if (m_xpos + _move >= m_backgroundWidth - m_width / 4)
	{
		m_xpos = m_backgroundWidth - m_width / 4;
		return;
	}

	if (m_xpos <= 0 && _playerXPos < m_width / 4 / 2)
		return;
	else if (_playerXPos >= m_backgroundWidth - m_width / 2)
		return;


	m_xpos += _move;
}

void Camera::Render(HDC _hdc)
{
	m_background->Render(_hdc, 0, 0, m_width, m_height, m_xpos, m_ypos+470);
}