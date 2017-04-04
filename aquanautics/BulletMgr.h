#pragma once
class Bullet;
class BulletMgr : public SingleTon<BulletMgr> , public Object
{
private:

public:
	BulletMgr();
	~BulletMgr();

	bool Initialize();
	void Update(float deltaTime);
	void Render();

	void RegisterBullet(Bullet* b);
	void Remove(Bullet* bullet);
};

