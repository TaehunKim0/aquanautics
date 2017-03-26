#include "stdafx.h"
#include "Stage1.h"
#include"Urak.h"
#include"MainMenu.h"

Stage1::Stage1()
{
	printf("Stage 1 \n");
	GameTime::TotalFrame = 0;
}

Stage1::~Stage1()
{

}

bool Stage1::Initialize()
{
	player = PlayerMgr::GetInstance()->GetPlayer();
	background = new BackGround();
	progress = new ProgressRate();
	//label = new Label();

	AddChild(background);
	AddChild(player);
	AddChild(BulletMgr::GetInstance());

	AddChild(EnemySpawner::GetInstance());
	AddChild(CollisionMgr::GetInstance());
	AddChild(ItemMgr::GetInstance());
	AddChild(progress);
	

	//AddChild(label);

	Scene::Initialize();

	return true;
}

void Stage1::Release()
{
	Scene::Release();
	printf("Scene : Stage1 Release\n");
}

bool a = 0;

void Stage1::Update(float deltaTime)
{
	Scene::Update(deltaTime);






	if (progress->middleBoss)
	{
		background->CanScroll = false;

		if (!a)
			EnemySpawner::GetInstance()->SpawnShark(1000, 250);
		a = 1;
	}

	if (progress->lastBoss)
	{
		background->CanScroll = false;
		a = 0;

		if (!a)
			EnemySpawner::GetInstance()->SpawnKraken(1000, 250);
		a = 1;
	}

}

void Stage1::Render()
{
	Scene::Render();
}