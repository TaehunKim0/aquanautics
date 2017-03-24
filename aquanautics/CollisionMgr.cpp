#include "stdafx.h"
#include "CollisionMgr.h"


CollisionMgr::CollisionMgr()
{
	collisionList.reserve(10);
}


CollisionMgr::~CollisionMgr()
{
}

bool CollisionMgr::Initialize()
{


	return true;
}

void CollisionMgr::Update(float deltaTime)
{
	for(auto a : collisionList)
		for (auto b : collisionList)
		{
			if (a != b)
			{
				auto c =  CircleCollide(a, b);
				if (c == true)
				{
					a->IsCollideWith(b);
					b->IsCollideWith(a);
				}
			}
		}

}

void CollisionMgr::Render()
{
}

void CollisionMgr::RegisterCollision(Collision * collision)
{
	collisionList.push_back(collision);
}

bool CollisionMgr::CircleCollide(Collision * a, Collision * b)
{
	int ax = (a->Position.x + a->Center.x);
	int bx = (b->Position.x + b->Center.x);

	int ay = (a->Position.y + a->Center.y);
	int by = (b->Position.y + b->Center.y);

	auto deltaPos = ((ax - bx) * (ax - bx) + (ay - by) * (ay - by));

	if (a->radius + b->radius > deltaPos)
		return true;

	return false;
}
