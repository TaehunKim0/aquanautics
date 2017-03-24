#include "stdafx.h"
#include "AnimationSprite.h"


AnimationSprite::AnimationSprite(int frameSize, int frameDelay) : lastFrame(frameSize) , frameDelay(frameDelay) , AutoNext(1)
{
	spriteList.reserve(frameSize);
}

AnimationSprite::~AnimationSprite()
{
	spriteList.clear();
}

void AnimationSprite::AddFrame(Sprite * sprite)
{
	sprite->Parent = this;

	spriteList.push_back(sprite);
}

void AnimationSprite::SetCurrentFrame(int frame)
{
	currentFrame = frame;
}

void AnimationSprite::NextFrame()
{
	currentFrame++;

	if (currentFrame > lastFrame)
		currentFrame = 0;
}

void AnimationSprite::Update(float deltaTime)
{
	Object::Update(deltaTime);
	
	for (auto sprite : spriteList)
	{
		sprite->Update(deltaTime);
	}

	if (frameDelay == 0 || AutoNext == false)
		return;

	if (GameTime::TotalFrame % frameDelay == 0)
	{
		NextFrame();
		printf("다음 프레임으로 %d\n", currentFrame);
	}
	printf("GTF : %d", GameTime::TotalFrame % frameDelay);
}

void AnimationSprite::Render()
{
	Object::Render();
	printf("%d 번애니 렌더링\n", currentFrame);
	auto sprite = spriteList.at(currentFrame);


	sprite->Render();
}

