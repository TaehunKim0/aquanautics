#pragma once
class Bullet;
class Player : public Object
{
private:
	Sprite* player;
	Sprite* p;
	float speed;

	Collision * m_collision;
public:
	Player();
	~Player();

	bool Initialize();
	void Update(float deltaTime);
	void Render();

	void Attack();

	void IsCollisionWith(Collision* other);
};