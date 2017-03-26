#pragma once
namespace SharkDirection
{
	enum Enum
	{
		Up,Down , Left , Right , Attack , NAttack
	};
}

class Shark : public Object
{
public:
	Sprite* shark;
	Collision* m_collision;

	int lifeCount;
	bool IsAppear;

	SharkDirection::Enum sharkDirection;

	int r;
	int a;

public:
	Shark();
	~Shark();

	bool Initialize();
	void Render();
	void Update(float deltaTime);

	void IsCollisionWith(Collision * other);

	void Move();
};