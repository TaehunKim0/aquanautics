#pragma once
class ProgressRate : public Object
{
public:
	Sprite* progress;
	Sprite* progressbar;

	bool middleBoss;
	bool lastBoss;

public:
	ProgressRate();
	~ProgressRate();

	void Render();
	void Update(float deltaTime);
	bool Initialize();
};

