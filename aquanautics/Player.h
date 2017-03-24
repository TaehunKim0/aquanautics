#pragma once
class Bullet;
class AnimationSprite;
class Player : public Object
{
private:
	Sprite* player;
	AnimationSprite* life;
	int lifeCount;
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