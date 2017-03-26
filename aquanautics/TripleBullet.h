#pragma once
class Bullet;
class TripleBullet :  public Bullet
{
private:
	Sprite* bullet;
	Collision* m_collision;

public:
	TripleBullet();
	~TripleBullet();

	TripleBullet(float radius);

	bool Initialize();
	void Update(float deltaTime);
	void Render();
	int LifeTime;
	int deathTime;
	float radius;

	void IsCollisionWith(Collision* other);
};

