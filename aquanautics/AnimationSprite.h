#pragma once
class AnimationSprite : public Sprite
{
private:
	std::vector<Sprite*> spriteList;

	int currentFrame;
	int lastFrame;

	int frameDelay;

public:
	AnimationSprite(int frameSize , int frameDelay);
	~AnimationSprite();

	void AddFrame(Sprite* sprite);

	void SetCurrentFrame(int frame);

	void NextFrame();

	bool AutoNext;

	void Update(float deltaTime);
	void Render();
};

