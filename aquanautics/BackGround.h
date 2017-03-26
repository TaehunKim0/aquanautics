#pragma once
class BackGround : public Object
{
private:
	Sprite *back;
	Sprite* back2;

	

public:
	BackGround();
	~BackGround();

	bool Initialize();
	void Update(float deltaTime);
	void Render();
	bool CanScroll;
	void SetBackGround(std::wstring fileName);
	void Scrolling();
};