#pragma once
class CollisionMgr : public Object , public SingleTon<CollisionMgr>
{
private:
	std::vector<Collision*> collisionList;


public:
	CollisionMgr();
	~CollisionMgr();

	bool Initialize();
	void Update(float deltaTime);
	void Render();

	void RegisterCollision(Collision* collision);

	bool CircleCollide(Collision* a, Collision* b);
};