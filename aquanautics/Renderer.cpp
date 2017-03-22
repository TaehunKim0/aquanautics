#include "stdafx.h"
#include "Renderer.h"


Renderer::Renderer()
{
}


Renderer::~Renderer()
{
}

bool Renderer::Initialize(HWND handle, int width, int height, bool windowMode)
{
	if ((Direct3D = Direct3DCreate9(D3D_SDK_VERSION)) == NULL)
	{
		assert(!"Direct3D 积己 角菩");
		return false;
	}

	D3DPRESENT_PARAMETERS pp = {};
	pp.BackBufferWidth = width;
	pp.BackBufferHeight = height;
	pp.BackBufferFormat = D3DFMT_A8B8G8R8;
	pp.SwapEffect = D3DSWAPEFFECT_DISCARD;
	pp.hDeviceWindow = handle;
	pp.Windowed = windowMode;


	HRESULT hr;

	if FAILED(hr = Direct3D->CreateDevice(D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL, handle,
		D3DCREATE_SOFTWARE_VERTEXPROCESSING, &pp, &Device))
	{
		assert(!"Device 积己 角菩");
		return false;
	}

	return true;
}

void Renderer::Release()
{
	SAFE_RELEASE(Device);
	SAFE_RELEASE(Direct3D);
}

void Renderer::Begin()
{
	Device->BeginScene();
	Device->Clear(1.0f, NULL, D3DCLEAR_TARGET, D3DCOLOR_XRGB(100, 100, 100), 1.0f, 0);
}

void Renderer::End()
{
	Device->EndScene();
	Device->Present(NULL, NULL, NULL, NULL);
}
