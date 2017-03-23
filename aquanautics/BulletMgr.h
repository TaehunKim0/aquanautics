#pragma once
class Bullet;
class BulletMgr : public SingleTon<BulletMgr> , public Object
{
private:

	std::vector<Bullet*> bulletList;

public:
	BulletMgr();
	~BulletMgr();

	bool Initialize();
	void Update(float deltaTime);
	void Render();

	void RegisterBullet(Bullet* b);
};

