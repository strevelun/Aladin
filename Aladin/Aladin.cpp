#include <windows.h>
#include <tchar.h>
#include "CApp.h"
#include <d2d1.h>

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
    _In_opt_ HINSTANCE hPrevInstance,
    _In_ LPWSTR    lpCmdLine,
    _In_ int       nCmdShow)
{
    CApp::GetInstance()->Init(hInstance, nCmdShow);

    return CApp::GetInstance()->Run();
}