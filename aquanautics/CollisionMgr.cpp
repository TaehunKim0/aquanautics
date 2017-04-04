#include "stdafx.h"
#include "CollisionMgr.h"
#include"Collision.h"


CollisionMgr::CollisionMgr()
{
	printf("CollisionMgr 积己 \n");
	CollisionList.reserve(20);
	
}


CollisionMgr::~CollisionMgr()
{
	for (auto a : Children)
		if (a)
		{
			a->Release();
			delete a;
		}
}

bool CollisionMgr::Initialize()
{
	return true;
}

void CollisionMgr::Update(float deltaTime)
{
	Object::Update(deltaTime);

	for(auto a: CollisionList)
		for(auto b : CollisionList)
		{
			if (a != b)
			{
				//if (CircleCollide(a, b))
				//{
				//	a->IsCollide(b);
				//	b->IsCollide(a);
				//}
			}
		}
}

void CollisionMgr::Render()
{
}

void CollisionMgr::RegisterCollision(Collision * collision)
{
	CollisionList.push_back(collision);
}

bool CollisionMgr::CircleCollide(Collision * a, Collision* b)
{
	float ax = a->Parent->Position.x;
	float ay = a->Parent->Position.y;

	float bx = b->Parent->Position.x;
	float by = b->Parent->Position.y;

	//printf("ax : %f\n", ax);
	//printf("ay : %f\n", ay);

	//printf("bx : %f\n", bx);
	//printf("by : %f\n", by);

	if (a->Parent->Name == "eel")
	{
		//printf("Name : %s , X : %f, Y : %f\n", a->Parent->Name.c_str(), ax, ay);
		//printf("Name : %s , X : %f, Y : %f\n", b->Parent->Name.c_str(), ax, ay);
	}

	float ftemp = sqrt(pow(ax - bx, 2) + pow(ay - by, 2));

	if (ftemp <= (a->radius + b->radius))
		return true;

	//printf("Ftemp : %f\n", ftemp);

	return false;
}

void CollisionMgr::Remove(Collision * collision)
{
	auto iter = std::find(Children.begin(), Children.end(), collision);
	if (iter == Children.end())
		return;

	Children.erase(iter);
}

//for (auto a : collisionList)// 1 2 3
//{
//	if (a == false)
//		continue;

//	printf("Collision : %s\n", a->Parent->Name.c_str());
//	if (a->Parent->visible == false)
//	{
//		std::vector<Collision*>::iterator iter = std::find(collisionList.begin(), collisionList.end(), a);
//		printf("面倒眉 : %s 昏力\n", a->Parent->Name.c_str());
//		collisionList.erase(iter);
//	}

//	else
//		printf("else\n");
//}
//