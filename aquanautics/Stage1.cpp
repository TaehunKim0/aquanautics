#include "stdafx.h"
#include "Stage1.h"
#include"Urak.h"

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

	AddChild(background);
	AddChild(player);
	AddChild(BulletMgr::GetInstance());

	AddChild(EnemySpawner::GetInstance());
	AddChild(CollisionMgr::GetInstance());
	AddChild(ItemMgr::GetInstance());
	AddChild(progress);

	Scene::Initialize();

	return true;
}

void Stage1::Release()
{
	Scene::Release();
}

void Stage1::Update(float deltaTime)
{
	Scene::Update(deltaTime);

	if (GameTime::TotalFrame == 100)
		EnemySpawner::GetInstance()->SpawnEnemy(900, 250);

	//printf("///\n");
}

void Stage1::Render()
{
	Scene::Render();
}
