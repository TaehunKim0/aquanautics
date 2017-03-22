#pragma once
class Renderer : public SingleTon<Renderer>
{
public:
	LPDIRECT3D9 Direct3D;
	LPDIRECT3DDEVICE9 Device;

public:
	Renderer();
	~Renderer();

	bool Initialize(HWND handle, int width, int height, bool windowMode);

	void Release();
	void Begin();
	void End();
};

