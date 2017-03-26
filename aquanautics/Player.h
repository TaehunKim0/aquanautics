#pragma once
class Bullet;
class AnimationSprite;
class Weapon;
class AddOnPlayer;

class Director;
class Player : public Object
{
private:
	AnimationSprite* player;
	AnimationSprite* life;
	AnimationSprite* nuclear;
	//AddOnPlayer* add;
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

	void Release();

	void Attack();
	void Move();
	void IsCollisionWith(Collision* other);
	
	int IsAddOnPlayer;

	void Cheat();
};