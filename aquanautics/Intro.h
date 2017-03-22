#pragma once
class Sprite;
class Intro : public Scene
{
private:	
	Player* player;

public:
	Intro();
	~Intro();

	bool Initialize();
	void Release();

	void Update(float deltaTime);
	void Render();
};

