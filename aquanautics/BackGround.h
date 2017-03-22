#pragma once
class BackGround : public Object
{
private:
	Sprite *back;

public:
	BackGround();
	~BackGround();

	bool Initialize();
	void Update(float deltaTime);
	void Render();

	void SetBackGround(std::wstring fileName);
};

