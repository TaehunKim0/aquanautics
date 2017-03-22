#pragma once
class Player : public Object
{
private:
	Sprite* player;
	Sprite* p;
public:
	Player();
	~Player();

	bool Initialize();
	void Update(float deltaTime);
	void Render();
};

