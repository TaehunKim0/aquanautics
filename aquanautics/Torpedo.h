#pragma once
class Bullet;
class Torpedo : public Bullet
{
private:
	Sprite* bullet;
	Collision* m_collision;

public:
	Torpedo();
	~Torpedo();

	bool Initialize();
	void Update(float deltaTime);
	void Render();

	void IsCollisionWith(Collision* other);
};

