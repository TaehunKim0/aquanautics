#pragma once
class Application
{
private:
	HWND handle;

public:
	Application();
	~Application();

	bool Initialize(std::wstring title, int width, int height, bool windowMode);

	void Release();

	void Run();

private:
	HWND _CreateWindow(std::wstring title, int width, int height, bool windowMode);

	static LRESULT CALLBACK WndProc(HWND hWnd, UINT Msg, WPARAM wParam, LPARAM lParam);
};

