#pragma once

class Sprite : public Object
{
private:
public:
	LPD3DXSPRITE D3DSprite;
	Texture* Texture;

public:
	Sprite();
	virtual ~Sprite();

	bool Initialize(std::wstring fileName);

	void Release();

	virtual void Update(float deltaTime);

	virtual void Render();


};

