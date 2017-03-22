#include "stdafx.h"
#include"Intro.h"

Intro::Intro()
{
	printf("Intro »ý¼º \n");
}

Intro::~Intro()
{
}

bool Intro::Initialize()
{
	player = PlayerMgr::GetInstance()->GetPlayer();

	AddChild(player);

	Scene::Initialize();

	return true;
}

void Intro::Release()
{
	Scene::Release();
}

void Intro::Update(float deltaTime)
{
	Scene::Update(deltaTime);
}

void Intro::Render()
{
	Scene::Render();
}
