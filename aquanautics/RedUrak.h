#pragma once
class RedUrak : public Object
{
private:
	Sprite* redurak;
	Collision* m_collision;

	int speed;
	int lifeCount;


public:
	RedUrak();
	~RedUrak();

	void Update(float deltaTime);
	void Render();
	bool Initialize();

	void IsCollisionWith(Collision * other);

	void Attack();
};

