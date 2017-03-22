#include "stdafx.h"
#include "Director.h"
#include"Scene.h"

Director::Director() : CurrentScene(nullptr)
{
}

Director::~Director()
{
}

bool Director::LoadScene(Scene * newScene)
{
}

void Director::Update(float deltaTime)
{
}

void Director::Render()
{
}
