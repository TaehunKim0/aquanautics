#include"stdafx.h"
#include"Application.h"
#include"Director.h"

#include"Intro.h"
#include"MainMenu.h"
#include"Stage1.h"


INT WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, INT)
{
#if _DEBUG
	AllocConsole();
	FILE* stream;
	freopen_s(&stream, "CON", "w", stdout);

#endif
	if (Application::GetInstance()->Initialize(WINDOW_TITLE, WINDOW_WIDTH, WINDOW_HEIGHT, WINDOW_MODE))
	{
		Director::GetInstance()->LoadScene(new MainMenu());

		Application::GetInstance()->Run();
		Application::GetInstance()->Release();
	}

#if _DEBUG
	FreeConsole();
#endif
}