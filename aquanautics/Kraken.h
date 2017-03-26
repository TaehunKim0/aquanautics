#pragma once
class Kraken : public Object
{
public:
	Sprite* kraken;
	Collision* m_collision;

public:
	Kraken();
	~Kraken();

	bool Initialize();
	void Render();
	void Update(float deltaTime);

	void IsCollisionWith(Collision * other);

	void Attack();
};