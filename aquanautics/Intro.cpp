#include "stdafx.h"
#include"Intro.h"
#include"Director.h"

#include"Intro.h"
#include"MainMenu.h"
#include"Stage1.h"
Intro::Intro()
{
	printf("Intro »ý¼º \n");
}

Intro::~Intro()
{
}

bool Intro::Initialize()
{
	
	return true;
}

void Intro::Release()
{
	Scene::Release();
}

void Intro::Update(float deltaTime)
{
	Scene::Update(deltaTime);

	if (Input::IsKeyDown('I'))
		Director::GetInstance()->LoadScene(new Intro());

	if (Input::IsKeyDown('M'))
		Director::GetInstance()->LoadScene(new MainMenu());

	if (Input::IsKeyDown('S'))
		Director::GetInstance()->LoadScene(new Stage1());
}

void Intro::Render()
{
	Scene::Render();
}
