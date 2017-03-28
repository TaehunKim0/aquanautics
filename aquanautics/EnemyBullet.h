#pragma once
class EnemyBullet : public Bullet
{
private:
	std::wstring tex;
	Sprite *bullet;
	Collision* m_collision;

public:
	EnemyBullet();
	EnemyBullet(std::wstring text);
	~EnemyBullet();

	bool Initialize();
	void Update(float deltaTime);
	void Render();

	void IsCollisionWith(Collision* other);
};