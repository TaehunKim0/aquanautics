#pragma once
class Item : public Object
{
private:
	Collision * m_collision;

	


public:
	Item(int x ,int y);
	~Item();

	void Update(float deltaTime);
	void Render();
	bool Initialize();

	void IsCollisionWith(Collision* collsion);
};

