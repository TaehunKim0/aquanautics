#include "stdafx.h"
#include "BackGround.h"


BackGround::BackGround()
{
}


BackGround::~BackGround()
{
}

bool BackGround::Initialize()
{
	back = new Sprite();

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
	if (back->Texture == nullptr)
	{
		back->Initialize(fileName);
	}

	else
	{
		back->Texture = nullptr;
		back->Initialize(fileName);
	}
}
