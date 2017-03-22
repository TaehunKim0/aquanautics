#include "stdafx.h"
#include "Texture.h"
#include"Renderer.h"

Texture::Texture() : FileName(L"") , Size(0.0f,0.0f)
{
}

Texture::~Texture()
{
}

bool Texture::Initiallize(std::wstring fileName)
{
	HRESULT hr;
	hr = D3DXCreateTextureFromFileEx(
		Renderer::GetInstance()->Device,
		fileName.c_str(),
		D3DX_DEFAULT_NONPOW2, D3DX_DEFAULT_NONPOW2,
		1, 0, D3DFMT_A8R8G8B8, D3DPOOL_MANAGED,
		D3DX_DEFAULT, D3DX_DEFAULT, NULL, NULL, NULL,
		&D3DTexture
	);

	if FAILED(hr)
	{
		assert(!"Texture 생성 실패");
		return false;
	}

	D3DSURFACE_DESC desc;
	if FAILED(D3DTexture->GetLevelDesc(0, &desc))
	{
		assert(!"Texture 정보 가져오기 실패");
		return false;
	}

	Size.x = static_cast<float>(desc.Width);
	Size.y = static_cast<float>(desc.Height);

	FileName = fileName;

}

void Texture::Release()
{
	SAFE_RELEASE(D3DTexture);
}
