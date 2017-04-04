#pragma once
class Bullet;
class Torpedo : public Bullet
{
public:
	Sprite* bullet;
//	Collision* m_collision;

	std::wstring tt;

	bool IsTexted;

public:
	Torpedo();
	Torpedo(std::wstring texture);
	~Torpedo();

	bool Initialize();
	void Update(float deltaTime);
	void Render();

	void IsCollisionWith(Collision* other);

	void SetTorpedoTexture(std::wstring texture);
};

