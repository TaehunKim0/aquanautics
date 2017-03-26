#include "stdafx.h"
#include "EnemySpawner.h"
#include"Urak.h"
#include"RedUrak.h"

#include"Shark.h"
#include"Kraken.h"

EnemySpawner::EnemySpawner()
{
}


EnemySpawner::~EnemySpawner()
{
}

bool EnemySpawner::Initialize()
{
	Object::Initialize();

	return true;
}

void EnemySpawner::Update(float deltaTime)
{
	Object::Update(deltaTime);

	for (auto a : enemyList)
		a->Update(deltaTime);

}

void EnemySpawner::Render()
{
	Object::Render();

	for (auto a : enemyList)
		a->Render();
}

void EnemySpawner::SpawnEnemy(int x, int y)
{
	srand(time(NULL));
	int r = rand() % 1;

	switch (r)
	{
	case 0:
		{
		auto e = new Urak();
		e->Initialize();

		enemyList.push_back(e);

		e->SetPostion(x, y);
		break;
		}
	case 1:
	{
		auto e = new RedUrak();
		e->Initialize();

		enemyList.push_back(e);

		e->SetPostion(x, y);
		break;
	}

	default:
		break;
	}



	

	printf("Spawn Enemy\n");
}

void EnemySpawner::SpawnShark(int x, int y)
{
}

void EnemySpawner::SpawnKraken(int x, int y)
{
}
