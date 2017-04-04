#include "stdafx.h"
#include "BulletMgr.h"
#include"Bullet.h"

BulletMgr::BulletMgr()
{
	printf("BulletMgr »ý¼º\n");

	Name = "BulletMgr";
}

BulletMgr::~BulletMgr()
{
	for (auto a : Children)
		if (a)
		{
			a->Release();
			delete a;
		}
}

bool BulletMgr::Initialize()
{
	for each(auto child in Children)
		child->Initialize();

	return false;
}

void BulletMgr::Update(float deltaTime)
{
	Object::Update(deltaTime);
}

void BulletMgr::Render()
{
	Object::Render();
}

void BulletMgr::RegisterBullet(Bullet * b)
{
	AddChild(b);
}

void BulletMgr::Remove(Bullet * bullet)
{
	bullet->Destroy();
}
