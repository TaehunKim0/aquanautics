#pragma once
class Stage2 : public Scene
{
private:
	Player* player;
	BackGround* background;

public:
	Stage2();
	~Stage2();

	bool Initialize();
	void Update(float deltaTime);
	void Render();
};

