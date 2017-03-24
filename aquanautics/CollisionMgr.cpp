#include "stdafx.h"
#include "CollisionMgr.h"


CollisionMgr::CollisionMgr()
{
	collisionList.reserve(10);
	printf("CollisionMgr »ý¼º \n");
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
				if (CircleCollide(a, b))
				{
					a->IsCollide(b);
					b->IsCollide(a);
				}
			}
				
		}
		

	/*for (auto a : collisionList)
	{
		if (a->Parent->visible == false)
		{
			SAFE_DELETE(a->Parent);
			std::vector<Collision*>::iterator iter = std::find(collisionList.begin(), collisionList.end(), a);
			collisionList.erase(iter);
		}

		else
			printf("else\n");
	}*/

	Object::Update(deltaTime);
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
	float ax = a->Position.x + a->Center.x;
	float ay = a->Position.y + a->Center.y;

	float bx = b->Position.x + b->Center.x;
	float by = b->Position.y +  b->Center.y;

	//printf("ax : %f\n", ax);
	//printf("ay : %f\n", ay);

	//printf("bx : %f\n", bx);
	//printf("by : %f\n", by);

	float ftemp = sqrt(pow(ax - bx, 2) + pow(ay - by, 2));

	if (ftemp <= (a->radius + b->radius))
		return true;

	//printf("Ftemp : %f\n", ftemp);

	return false;
}
