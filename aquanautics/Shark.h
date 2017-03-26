#pragma once
class Shark : public Object
{
public:
	Sprite* shark;
	Collision* m_collision;

public:
	Shark();
	~Shark();

	bool Initialize();
	void Render();
	void Update(float deltaTime);

	void IsCollisionWith(Collision * other);

	void Attack();
};