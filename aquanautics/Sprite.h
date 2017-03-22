#pragma once
class Sprite : public Object
{
private:
public:
	LPD3DXSPRITE D3DSprite;


public:
	Sprite();
	virtual ~Sprite();

	bool Initialize(std::wstring fileName);

	void Release();

	virtual void Update();

	virtual void Render();


};

