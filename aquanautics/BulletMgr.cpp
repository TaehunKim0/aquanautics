#include "stdafx.h"
#include "BulletMgr.h"
#include"Bullet.h"

BulletMgr::BulletMgr()
{
	printf("BulletMgr »ý¼º\n");
	bulletList.reserve(100);

	Name = "BulletMgr";
}

BulletMgr::~BulletMgr()
{
}

bool BulletMgr::Initialize()
{
	for (auto b : bulletList)
		b->Initialize();

	return false;
}

void BulletMgr::Update(float deltaTime)
{
	std::vector<Bullet*>::iterator iter;

	iter = bulletList.begin();

  	for (; iter != bulletList.end();)
	{
 		if (!((*iter)->visible))
		{
			iter = bulletList.erase(iter);
			continue;
		}

		++iter;
	}

	for (auto b : bulletList)
		b->Update(deltaTime);

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
