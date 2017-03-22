#pragma once
class Input
{
public:
	static bool IsKeyDown(int keycode)
	{
		return GetKeyState(keycode) & 0x8000;
	}

	static bool IsKeyPressed(int keycode)
	{
		return GetKeyState(keycode) & 0x8001;
	}
};

