#include "stdafx.h"
#include "BackGround.h"


BackGround::BackGround()
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

	AddChild(back);
	return true;
}

void BackGround::Update(float deltaTime)
{
	Object::Update(deltaTime);
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