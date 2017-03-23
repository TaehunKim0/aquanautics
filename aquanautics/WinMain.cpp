#include"stdafx.h"
#include"Application.h"
#include"Director.h"

#include"Intro.h"

INT WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, INT)
{
#if _DEBUG
	AllocConsole();
	FILE* stream;
	freopen_s(&stream, "CON", "w", stdout);
#endif

	if (Application::GetInstance()->Initialize(WINDOW_TITLE, WINDOW_WIDTH, WINDOW_HEIGHT, WINDOW_MODE))
	{
		Director::GetInstance()->LoadScene(new Intro());

		Application::GetInstance()->Run();
		Application::GetInstance()->Release();

		GameTime::CurrentFrame++;
		GameTime::TotalFrame++;

		if (GameTime::CurrentFrame > 60)
			GameTime::CurrentFrame = 0;
	}

#if _DEBUG
	FreeConsole();
#endif
}