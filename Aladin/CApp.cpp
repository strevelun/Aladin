#include "CApp.h"
#include "CBitmap.h"
#include "CDC.h"

CApp* CApp::m_inst = nullptr;

LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    return CApp::GetInstance()->Proc(hWnd, message, wParam, lParam);
}


void CApp::Init(HINSTANCE hInstance, int nCmdShow)
{

    WNDCLASSEX wcex;

    wcex.cbSize = sizeof(WNDCLASSEX);
    wcex.style = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc = WndProc;
    wcex.cbClsExtra = 0;
    wcex.cbWndExtra = sizeof(LONG_PTR);
    wcex.hInstance = hInstance;
    wcex.hIcon = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_APPLICATION));
    wcex.hCursor = LoadCursor(NULL, IDC_ARROW);
    wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
    wcex.lpszMenuName = NULL;
    wcex.lpszClassName = L"szWindowClass";
    wcex.hIconSm = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_APPLICATION));

    RegisterClassEx(&wcex);

    m_hWnd = CreateWindow(
        L"szWindowClass", L"szTitle",
        WS_OVERLAPPED | WS_SYSMENU,
        CW_USEDEFAULT, CW_USEDEFAULT,
        WIDTH, HEIGHT,
        NULL,
        NULL,
        hInstance, NULL);

    m_player = new Player(m_hWnd);

    RECT rc;
    GetClientRect(m_hWnd, &rc);

    ShowWindow(m_hWnd, nCmdShow);   // WM_PAINT 호출
    UpdateWindow(m_hWnd);


}

void CApp::Input()
{
    m_player->Input();
}

void CApp::Update()
{

}

void CApp::Render()
{
    if (m_hdc == NULL) return;

    HDC hMemDC = CreateCompatibleDC(m_hdc);
    RECT rt;
    rt.right = WIDTH;
    rt.bottom = HEIGHT;

    //FillRect(hMemDC, &rt, (HBRUSH)GetStockObject(WHITE_BRUSH));

    //m_cdc.RenderScreen(hMemDC, 0, 0, WIDTH, HEIGHT);

    //m_player->Render(hMemDC);

    Rectangle(hMemDC, 10, 10, 100, 100);

    HBITMAP backBit = CreateCompatibleBitmap(hMemDC, rt.right, rt.bottom);
    HBITMAP oldBackBit = (HBITMAP)SelectObject(hMemDC, backBit);




    BitBlt(m_hdc, 0, 0, WIDTH, HEIGHT, hMemDC, 0, 0, SRCCOPY);

    ReleaseDC(m_hWnd, hMemDC);
}

int CApp::Run()
{
    MSG msg;
    CBitmap bitmap(m_hWnd, L"background.bmp");
    m_cdc.SetBitmap(&bitmap);
    InvalidateRgn(m_hWnd, NULL, false);
    //m_cdc.RenderScreen(m_hdc, 0, 0, WIDTH, HEIGHT);

    while (true)
    {
        if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
        {
            if (msg.message == WM_QUIT) break;

            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }

        Input();
        // game loop
        Update();
        InvalidateRgn(m_hWnd, NULL, false);
    }

    return (int)msg.wParam;
}

LRESULT CApp::Proc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    PAINTSTRUCT ps;
    m_hWnd = hWnd;

    switch (message)
    {
    case WM_CREATE:  // CreateWindow( ) 호출
        break;

    case WM_PAINT:
    {
        m_hdc = BeginPaint(hWnd, &ps);

        Render();

        EndPaint(hWnd, &ps);
    }
    break;
    case WM_DESTROY:
        PostQuitMessage(0);
        break;
    default:
        return DefWindowProc(hWnd, message, wParam, lParam);
    }
    return 0;
}

