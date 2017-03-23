#include "stdafx.h"
#include "BulletMgr.h"
#include"Bullet.h"

BulletMgr::BulletMgr()
{
}


BulletMgr::~BulletMgr()
{
}

bool BulletMgr::Initialize()
{
	bulletList.reserve(10);
	for (auto b : bulletList)
		b->Initialize();

	return false;
}

void BulletMgr::Update(float deltaTime)
{
	for (auto b : bulletList)
	{
		b->Update(deltaTime);

		if (b->LifeTime == b->deathTime)
		{
			//std::vector<Bullet*>::iterator iter = std::find(bulletList.begin(), bulletList.end(), b);
			//bulletList.erase(iter);
		}
	}
}

void BulletMgr::Render()
{
	for (auto b : bulletList)
		b->Render();
}

void BulletMgr::RegisterBullet(Bullet * b)
{
	bulletList.push_back(b);
}