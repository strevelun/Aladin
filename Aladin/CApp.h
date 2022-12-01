#pragma once
#include <windows.h>

#define MAX_LOADSTRING 100
#define WIDTH           1680 // 4773 2.84
#define HEIGHT          1080
#include "CDC.h"
#include "Player.h"

class CApp
{
private:
	static CApp* m_inst;

	WCHAR szTitle[MAX_LOADSTRING];
	WCHAR szWindowClass[MAX_LOADSTRING];

	HWND	m_hWnd;
	HDC		m_hdc;

	CDC m_cdc;

	HINSTANCE m_hInstance;

	Player* m_player;
	int backgroundX = 0, backgroundY = 0;

private:
	CApp() { m_hdc = NULL; }
	~CApp() {}

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