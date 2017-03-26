#include "stdafx.h"
#include "EnemySpawner.h"
#include"Urak.h"

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
	int r = rand() % 2;

	auto e = new Urak();
	e->Initialize();



	enemyList.push_back(e);

	e->SetPostion(x, y);

	printf("Spawn Enemy\n");
}
