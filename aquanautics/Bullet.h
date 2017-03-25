#pragma once
class Bullet : public Object
{
private:

public:
	Bullet();
	~Bullet();

	virtual bool Initialize();
	virtual void Update(float deltaTime);
	virtual void Render();

	int LifeTime;
	int deathTime;

	virtual void IsCollisionWith(Collision* collision);
};

