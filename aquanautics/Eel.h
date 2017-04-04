#pragma once
class Eel : public Object
{
private:
	Sprite* eel;
	//Collision* m_collision;

	int speed;
	int lifeCount;

	bool Cancollsion;
	int r;
public:
	Eel();
	~Eel();

	bool Initialize();
	void Update(float deltaTime);
	void Render();

	void IsCollisionWith(Collision* other);

	void Attack();
};

