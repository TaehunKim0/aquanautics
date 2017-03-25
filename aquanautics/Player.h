#pragma once
class Bullet;
class AnimationSprite;
class Weapon;

class Player : public Object
{
private:
	Sprite* player;
	AnimationSprite* life;
	AnimationSprite* nuclear;

	int lifeCount;
	float speed;

	Collision * m_collision;
	Weapon* weapon;

	int collisionTime;
	bool Cancollision;



public:
	Player();
	~Player();

	bool Initialize();
	void Update(float deltaTime);
	void Render();

	void Attack();
	void Move();
	void IsCollisionWith(Collision* other);
	
	bool IsAddOnPlayer;
};