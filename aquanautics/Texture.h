#pragma once


class Texture
{
public:
	LPDIRECT3DTEXTURE9 D3DTexture;
	std::wstring FileName;
	D3DXVECTOR2 Size;

public:
	Texture();
	virtual ~Texture();

	bool Initiallize(std::wstring fileName);

	void Release();
};

