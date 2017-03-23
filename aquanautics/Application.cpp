#include "stdafx.h"
#include "Application.h"
#include"Renderer.h"
#include"Director.h"

Application::Application()
{
}


Application::~Application()
{
}

bool Application::Initialize(std::wstring title, int width, int height, bool windowMode)
{
	if ((handle = _CreateWindow(title, width, height, windowMode))== NULL)
		return false;

	if (Renderer::GetInstance()->Initialize(handle, width, height, windowMode) == false)
		return false;

		return true;
}

void Application::Release()
{
	Renderer::GetInstance()->Release();
}

void Application::Run()
{
	ShowWindow(handle, SW_SHOWDEFAULT);

	if (Director::GetInstance()->CurrentScene == nullptr)
	{
		assert(!"CurrentScene 이 null 입니다");
		return;
	}

	MSG msg = {};
	while (msg.message != WM_QUIT)
	{
		if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}

		else
		{
			Renderer::GetInstance()->Begin();
			Director::GetInstance()->Update(16.f);
			Director::GetInstance()->Render();
			Renderer::GetInstance()->End();

			GameTime::CurrentFrame++;
			GameTime::TotalFrame++;

			if (GameTime::CurrentFrame > 60)
				GameTime::CurrentFrame = 0;

			
		}
	}


}

HWND Application::_CreateWindow(std::wstring title, int width, int height, bool windowMode)
{
	WNDCLASS wc = {};
	wc.lpszClassName = WINDOW_TITLE;
	wc.lpfnWndProc = WndProc;

	wc.hCursor = LoadCursor(NULL, IDC_ARROW);

	if (RegisterClass(&wc) == NULL)
		return 0;

	DWORD style;

	if (windowMode)
		style = WS_OVERLAPPEDWINDOW;
	else
		style = WS_EX_TOPMOST | WS_POPUP;

	HWND handle = CreateWindow(title.c_str(), title.c_str(), style, 0, 0, width, height, NULL, NULL, wc.hInstance, NULL);

	if (handle == NULL)
		return 0;

	return handle;
}

LRESULT Application::WndProc(HWND hWnd, UINT Msg, WPARAM wParam, LPARAM lParam)
{
	switch (Msg)
	{
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	}

	return DefWindowProc(hWnd, Msg, wParam, lParam);
}
