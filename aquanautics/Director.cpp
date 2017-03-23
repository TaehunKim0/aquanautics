#include "stdafx.h"
#include "Director.h"
#include"Renderer.h"
#include"Scene.h"

Director::Director() : CurrentScene(nullptr)
{
}

Director::~Director()
{
}

bool Director::LoadScene(Scene * newScene)
{
	if (CurrentScene)
	{
		CurrentScene->Release();
		delete CurrentScene;
	}

	CurrentScene = newScene;
	return CurrentScene->Initialize();
}

void Director::Update(float deltaTime)
{
	if (CurrentScene == nullptr)
		return;

	CurrentScene->Update(deltaTime);

	
}

void Director::Render()
{
	if (CurrentScene == nullptr)
		return;

	CurrentScene->Render();
}
