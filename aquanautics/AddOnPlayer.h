#pragma once
class Player;
class AddOnPlayer : public Object
{
private:
	Sprite* addonplayer;
	Player* player;

public:
	AddOnPlayer();
	~AddOnPlayer();

	bool Initialize();
	void Update(float deltaTime);
	void Render();

	void Attack();
};

