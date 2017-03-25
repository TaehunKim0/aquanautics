#pragma once
class Urak;
class Stage1 : public Scene
{
private:

	Player* player;
	BackGround* background;
	Urak* urak;
	ProgressRate* progress;

public:
	Stage1();
	~Stage1();

	bool Initialize();
	void Release();

	void Update(float deltaTime);
	void Render();
};

