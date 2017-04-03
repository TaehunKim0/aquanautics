#pragma once
class Urak;
class Label;
class MainMenu;
namespace Boss
{
	enum ENUM
	{
		shark,
		hydra,
		Done
	};
}

class Stage1 : public Scene
{
private:
	Player* player;
	BackGround* background;
	Urak* urak;
	ProgressRate* progress;
	Label* label;

	bool CanSpawn;
	bool IsShark;


public:
	Stage1();
	~Stage1();

	bool Initialize();
	void Release();

	void Update(float deltaTime);
	void Render();

	Boss::ENUM boss;
};

