#pragma once
class BackGround : public Object
{
private:
	Sprite *back;
	Sprite* back2;

	bool CanScroll;


public:
	BackGround();
	~BackGround();

	bool Initialize();
	void Update(float deltaTime);
	void Render();

	void SetBackGround(std::wstring fileName);
	void Scrolling();
};