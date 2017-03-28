#include "stdafx.h"
#include "EnemySpawner.h"
#include"Urak.h"
#include"Eel.h"
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

	for (auto a : enemyList)
		a->Initialize();

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
	auto r = (rand() % 2) + 1;
	printf("R : %d\n", r);
	switch (r)
	{
	case 1:
	{
		auto e = new Urak();
		e->Initialize();
		enemyList.push_back(e);
		e->SetPostion(x, y);
	}
	break;

	case 2:
	{
		auto e = new Eel();
		e->Initialize();
		enemyList.push_back(e);
		e->SetPostion(x, y);
	}
	break;

	default:
		printf("Spawner Default\n");
		break;
	}

	
	
}

void EnemySpawner::SpawnShark(int x, int y)
{
	auto sh = new Shark();
	sh->Initialize();

	enemyList.push_back(sh);

	sh->SetPostion(x, y);
}

void EnemySpawner::SpawnKraken(int x, int y)
{
}
