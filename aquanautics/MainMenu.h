#pragma once
class MainMenu : public Scene
{
private:
	AnimationSprite* menu;
	Sprite* main;

	int menuIndex;

	Sprite* howtoplay;
	

public:
	MainMenu();
	~MainMenu();

	bool Initialize();
	void Release();

	void Update(float deltaTime);
	void Render();
};

