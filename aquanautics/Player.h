#pragma once
class Bullet;
class Player : public Object
{
private:
	Sprite* player;
	Sprite* p;

public:
	Player();
	~Player();

	bool Initialize();
	void Update(float deltaTime);
	void Render();

	void Attack();
};