#pragma once
#include <windows.h>

#define MAX_LOADSTRING 100
#define WIDTH           1680
#define HEIGHT          1080

class CApp
{
private:
	static CApp* m_inst;

	WCHAR szTitle[MAX_LOADSTRING];
	WCHAR szWindowClass[MAX_LOADSTRING];

	HWND	m_hwnd;
	HDC		m_hdc;

	HINSTANCE m_hInstance;

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
	void Update();
	void Render();
	int Run();

	LRESULT CALLBACK Proc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);
};