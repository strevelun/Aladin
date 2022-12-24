#pragma once
#include <windows.h>

#define MAX_LOADSTRING 100
#define WIDTH           1200 // 30:22
#define HEIGHT          880
#include "CDC.h"
#include "Player.h"
#include "Background.h"
#include "Animation.h"
#include "Camera.h"

class CApp
{
private:
	static CApp* m_inst;

	WCHAR szTitle[MAX_LOADSTRING];
	WCHAR szWindowClass[MAX_LOADSTRING];

	HWND	m_hWnd;
	HDC		m_hdc;
	//CDC m_cdc;
	HINSTANCE m_hInstance;
	HDC m_backBuffer;

	Player* m_player;
	int backgroundX = 0, backgroundY = 250;
	Background* m_background;
	Camera* m_camera;

	LARGE_INTEGER		m_second;
	LARGE_INTEGER		m_time;
	float m_deltaTime = 0.0f;


private:
	CApp() { m_hdc = NULL; }
	~CApp() 
	{
		delete m_background;
		delete m_camera;
	}

public:
	static CApp* GetInstance()
	{
		if (m_inst == nullptr)  m_inst = new CApp();
		return m_inst;
	}

	void Init(HINSTANCE hInstance, int nCmdShow);
	void Input();
	void Update();
	void Render();
	int Run();

	LRESULT CALLBACK Proc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);
};