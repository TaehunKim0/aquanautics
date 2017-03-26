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

Sprite * AnimationSprite::GetCurrentFrame()
{
	auto sprite = spriteList.at(currentFrame);
	return sprite;
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
	}
	
}

void AnimationSprite::Render()
{
	Object::Render();
	auto sprite = spriteList.at(currentFrame);


	sprite->Render();
}

