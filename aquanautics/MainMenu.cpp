#include "stdafx.h"
#include "MainMenu.h"
#include"Stage1.h"

MainMenu::MainMenu() : menuIndex(0)
{
}


MainMenu::~MainMenu()
{
}

bool MainMenu::Initialize()
{
	menu = new AnimationSprite(4, 10);
	menu->AutoNext = false;

	
	//AddChild(menu);

	return false;
}

void MainMenu::Release()
{
	Scene::Release();
}

void MainMenu::Update(float deltaTime)
{
	Scene::Update(deltaTime);
	
	menuIndex = min(max(menuIndex, 0), 4);

	if (Input::IsKeyDown(VK_DOWN))
		menuIndex++;

	if (Input::IsKeyDown(VK_UP))
		menuIndex--;

	printf("%d \n", menuIndex);

	if (Input::IsKeyDown(VK_RETURN))
	{
		switch (menuIndex)
		{
		case 0:
			Director::GetInstance()->LoadScene(new Stage1());
			break;

		case 1://霸烙家俺
			break;

		case 2://规过
			break;

		case 3://珐欧
			break;

		case 4://农饭调
			break;
		}
	}
}

void MainMenu::Render()
{
	Scene::Render();
}
