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

	menu->AddFrame(Sprite::Create(L"Resources/UI/Menu/gamestart.png"));
	menu->AddFrame(Sprite::Create(L"Resources/UI/Menu/howtoplay.png"));
	menu->AddFrame(Sprite::Create(L"Resources/UI/Menu/ranking.png"));
	menu->AddFrame(Sprite::Create(L"Resources/UI/Menu/credit.png"));
	menu->AddFrame(Sprite::Create(L"Resources/UI/Menu/introduce.png"));
	menu->SetCurrentFrame(0);

	menu->AutoNext = 0;
	
	menu->Position.x += 800;
	menu->Position.y += 300;

	howtoplay = new Sprite();
	howtoplay->Initialize(L"Resources/Menu/howtoplay.png");

	introduce = new Sprite();
	introduce->Initialize(L"Resources/Menu/introduce.png");

	ranking = new Sprite();
	ranking->Initialize(L"Resources/Menu/ranking.png");

	credit = new Sprite();
	credit->Initialize(L"Resources/Menu/credit.png");

	AddChild(Sprite::Create(L"Resources/Map/menu.png"));

	AddChild(menu);
	AddChild(howtoplay);
	AddChild(introduce);
	AddChild(ranking);
	AddChild(credit);


	howtoplay->visible = false;
	introduce->visible = false;
	ranking->visible = false;
	credit->visible = false;



	Scene::Initialize();

	return true;

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

	if (menu->AutoNext == false)
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
			break;

		case 5:
			menu->SetCurrentFrame(4);
			break;
		}
	}
	if (menu->AutoNext == false)
	{
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
				howtoplay->visible = true;
				
				break;

			case 2://랭킹
				ranking->visible = true;

				break;

			case 3://크레딧
				credit->visible = true;
				break;

			case 4://게임소개
				introduce->visible = true;

				break;
			case 5:
				introduce->visible = true;
				break;

			default:
				printf("Menu Default\n");
				break;
			}
		}
	}

	if (Input::IsKeyDown('M'))
	{
		//Director::GetInstance()->LoadScene(new MainMenu());

		if (howtoplay->visible)
			howtoplay->visible = false;

		if (introduce->visible)
			introduce->visible = false;

		if (ranking->visible)
			ranking->visible = false;

		if (credit->visible)
			credit->visible = false;

	}
		
	
}

void MainMenu::Render()
{
	Scene::Render();
}
