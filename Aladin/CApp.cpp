#include "CApp.h"
#include "CBitmap.h"
#include "CDC.h"
#include <string>

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
    m_background = new Background(m_hWnd);

    RECT rc;
    GetClientRect(m_hWnd, &rc);

    ShowWindow(m_hWnd, nCmdShow);   // WM_PAINT 호출
    UpdateWindow(m_hWnd);

    QueryPerformanceFrequency(&m_second);
    QueryPerformanceCounter(&m_time);
}

void CApp::Input()
{
    m_player->Input(m_deltaTime);
}

void CApp::Update()
{
    LARGE_INTEGER	time;
    QueryPerformanceCounter(&time);

    m_deltaTime = (time.QuadPart - m_time.QuadPart) / (float)m_second.QuadPart;
    m_time = time;

    int playerXPos = m_player->GetXPos();
    int backgroundWidth = m_background->GetBitmap()->GetWidth();

    if (playerXPos >= m_background->GetBitmap()->GetWidth())
    {
        m_player->Update(m_deltaTime, false);
    }
    else if (playerXPos >= WIDTH / 2) // 넘어가면 배경 이동
    {
        backgroundX = playerXPos - (WIDTH / 2);
        m_player->Update(m_deltaTime, true);
    }
    else
        m_player->Update(m_deltaTime, false);
    
}

void CApp::Render()
{
    if (m_hdc == NULL) return;

    HDC hBackBufferDC = CreateCompatibleDC(m_hdc);
    RECT rt;
    GetClientRect(m_hWnd, &rt);

    HBITMAP hBackBufferBMP = CreateCompatibleBitmap(m_hdc, rt.right, rt.bottom);
    SelectObject(hBackBufferDC, hBackBufferBMP);

    FillRect(hBackBufferDC, &rt, (HBRUSH)GetStockObject(WHITE_BRUSH));
    
    m_background->Render(hBackBufferDC, 0,0, WIDTH, HEIGHT, backgroundX, backgroundY);

    m_player->Render(hBackBufferDC, m_deltaTime);

    BitBlt(m_hdc, 0, 0, WIDTH, HEIGHT, hBackBufferDC, 0, 0, SRCCOPY);


    DeleteDC(hBackBufferDC);
    DeleteObject(hBackBufferBMP);

    // 좌표 출력
    std::wstring tmpX = std::to_wstring(m_player->GetXPos());
    std::wstring tmpY = std::to_wstring(m_player->GetYPos());
    std::wstring xyPosText = tmpX + L", " + tmpY;   // x, y

    TextOut(m_hdc, 10, 10, xyPosText.c_str(), xyPosText.size());
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

