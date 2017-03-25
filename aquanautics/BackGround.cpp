#include "stdafx.h"
#include "BackGround.h"


BackGround::BackGround() : CanScroll(1)
{
	printf("Background »ý¼º\n");
}

BackGround::~BackGround()
{
}

bool BackGround::Initialize()
{
	back = new Sprite();
	back->Initialize(L"Resources/Map/stage1.png");

	back2 = new Sprite();
	back2->Initialize(L"Resources/Map/stage1.png");
	back2->SetPostion(2500, 0);

	
	AddChild(back);
	AddChild(back2);

	return true;
}

void BackGround::Update(float deltaTime)
{
	Object::Update(deltaTime);

	if (CanScroll)
		Scrolling();
}

void BackGround::Render()
{
	Object::Render();


}

void BackGround::SetBackGround(std::wstring fileName)
{
	back->Initialize(fileName);
	printf("SetBacground : %s \n", fileName);
}

void BackGround::Scrolling()
{
	back->Position.x -= 5;

	back2->Position.x -= 5;

	if (back2->Position.x == -2500)
		back2->Position.x = 2500;

	if (back->Position.x == -2500)
		back->Position.x = 2500;
}

