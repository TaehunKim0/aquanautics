#pragma once
class Bullet : public Object
{
private:
	Sprite* bullet;
public:
	Bullet();
	~Bullet();

	bool Initialize();
	void Update(float deltaTime);
	void Render();
	int LifeTime;
	int deathTime;
};

