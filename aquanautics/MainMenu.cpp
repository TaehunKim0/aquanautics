#include "stdafx.h"
#include "MainMenu.h"
#include"Stage1.h"

MainMenu::MainMenu() : menuIndex(0)
{
	printf("Menu Scene \n");
}


MainMenu::~MainMenu()
{
}

bool MainMenu::Initialize()
{
	menu = new AnimationSprite(4, 10);
	menu->AutoNext = false;
	
	menu->AddFrame(Sprite::Create(L"Resources/UI/Menu/gamestart.png"));
	menu->AddFrame(Sprite::Create(L"Resources/UI/Menu/howtoplay.png"));
	menu->AddFrame(Sprite::Create(L"Resources/UI/Menu/ranking.png"));
	menu->AddFrame(Sprite::Create(L"Resources/UI/Menu/credit.png"));
	menu->AddFrame(Sprite::Create(L"Resources/UI/Menu/introduce.png"));
	menu->SetCurrentFrame(0);

	menu->AutoNext = false;
	menu->visible = true;

	AddChild(menu);
	//AddChild(Sprite::Create(L"Resources/Map/stage1.png"));
	Scene::Initialize();

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

	if (Input::IsKeyDown(VK_RETURN))
	{
		switch (menuIndex)
		{
		case -1:
			menu->SetCurrentFrame(0);
			break;

		case 0://게임 스타트
			menu->SetCurrentFrame(0);
			break;

		case 1://게임방법
			menu->SetCurrentFrame(1);
			break;

		case 2://랭킹
			menu->SetCurrentFrame(2);
			break;

		case 3://크레딧
			menu->SetCurrentFrame(3);
			break;

		case 4://게임소개
			menu->SetCurrentFrame(4);

		case 5:
			menu->SetCurrentFrame(4);
			break;
		}
	}

	if (Input::IsKeyDown(VK_RETURN))
	{
		switch (menuIndex)
		{
		case -1:
			Director::GetInstance()->LoadScene(new Stage1());
			break;

		case 0://게임 스타트
			Director::GetInstance()->LoadScene(new Stage1());
			break;

		case 1://게임방법
			
			break;

		case 2://랭킹
			
			break;

		case 3://크레딧
			
			break;

		case 4://게임소개
			

		case 5:
			
			break;
		}
	}
}

void MainMenu::Render()
{
	Scene::Render();
}
