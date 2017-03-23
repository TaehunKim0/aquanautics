#include "stdafx.h"
#include "AnimationSprite.h"


AnimationSprite::AnimationSprite(int frameSize, int frameDelay) : lastFrame(frameSize) , currentFrame(0) , frameDelay(frameDelay) , AutoNext(1)
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
	if (frameDelay == 0 || !AutoNext)
		return;

	if (GameTime::TotalFrame % frameDelay == 0)
		NextFrame();
}

