#include "stdafx.h"
#include "Stage1.h"


Stage1::Stage1()
{
}


Stage1::~Stage1()
{
}

bool Stage1::Initialize()
{
	player = PlayerMgr::GetInstance()->GetPlayer();
	background = new BackGround();
	
	
	AddChild(background);
	AddChild(player);
	AddChild(BulletMgr::GetInstance());

	Scene::Initialize();

	background->SetBackGround(L"Resources/Map/stage1.png");

	return false;
}

void Stage1::Release()
{
	Scene::Release();
}

void Stage1::Update(float deltaTime)
{
	Scene::Update(deltaTime);
}

void Stage1::Render()
{
	Scene::Render();
}
