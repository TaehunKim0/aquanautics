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
		assert(!"Direct3D 생성 실패");
		return false;
	}

	D3DPRESENT_PARAMETERS pp = {};
	pp.BackBufferWidth = width;
	pp.BackBufferHeight = height;
	pp.BackBufferFormat = D3DFMT_A8R8G8B8;
	pp.SwapEffect = D3DSWAPEFFECT_DISCARD;
	pp.hDeviceWindow = handle;
	pp.Windowed = windowMode;


	HRESULT hr;
	hr = Direct3D->CreateDevice(D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL, handle,
		D3DCREATE_SOFTWARE_VERTEXPROCESSING, &pp, &Device);

	if FAILED(hr)
	{
		assert(!"Device 생성 실패");
		return false;
	}
	switch (hr)
	{
	case D3DERR_INVALIDCALL:
		printf("메서드의 호출이 무효이다. 예를 들어, 메서드의 파라미터에 무효인 값이 설정되어 있는 경우 등이다");
		break;
	case D3DERR_NOTAVAILABLE:
		printf("이 장치는, 문의한 테크닉을 지원 하고 있지 않다.");
		break;
	case D3DERR_OUTOFVIDEOMEMORY:
		printf("Direct3D 가 처리를 실시하는데 충분한 디스플레이 메모리가 없다.");
		break;
	case D3D_OK:
		break;
	default:
		printf("어느 항목에도 해당x");

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
