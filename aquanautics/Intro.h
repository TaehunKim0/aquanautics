#pragma once

class Intro : public Scene
{
private:	

public:
	Intro();
	~Intro();

	bool Initialize();
	void Release();

	void Update(float deltaTime);
	void Render();
};

