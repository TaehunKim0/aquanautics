#include "stdafx.h"
#include "Stage1.h"
#include"Urak.h"
#include"MainMenu.h"

Stage1::Stage1() : CanSpawn(1)
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
	
	if(CanSpawn)
		if (GameTime::TotalFrame % 120 == 0)
		{
			srand(time(NULL));
			int y = 0;
			y = rand() % 4+1;

			switch (y)
			{
			case 1:
				y = 100;
				break;

			case 2:
				y = 230;
				break;

			case 3:
				y = 430;
				break;

			case 4:
				y = 530;
				break;
			}
			
			//printf("y: %d\n", y);

			EnemySpawner::GetInstance()->SpawnEnemy(1300, y);


		}
		




	if (progress->middleBoss)
	{
		background->CanScroll = false;

		if (!a)
			EnemySpawner::GetInstance()->SpawnShark(1000, 250);
		a = 1;

		CanSpawn = 0;
	}

	if (progress->lastBoss)
	{
		background->CanScroll = false;
		a = 0;

		if (!a)
			EnemySpawner::GetInstance()->SpawnKraken(1000, 250);
		a = 1;

		CanSpawn = 0;
	}

}

void Stage1::Render()
{
	Scene::Render();
}