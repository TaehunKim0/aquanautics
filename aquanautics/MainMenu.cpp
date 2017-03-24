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
	
	menu->Position.x += 600;
	menu->Position.y += 100;

	AddChild(Sprite::Create(L"Resources/Map/stage1.png"));
	AddChild(menu);
	
	Scene::Initialize();

	return true;

}

void MainMenu::Release()
{
	Scene::Release();
}

void MainMenu::Update(float deltaTime)
{
	printf("CurrentFrame : %d \n", menu->currentFrame);
	printf("GameTime :  %d \n", GameTime::TotalFrame);
	printf("AutoNext : %d \n", menu->AutoNext);

	//printf("Menu index : %d \n", menuIndex);

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

		case 0://���� ��ŸƮ
			menu->SetCurrentFrame(0);
			break;

		case 1://���ӹ��
			menu->SetCurrentFrame(1);
			break;

		case 2://��ŷ
			menu->SetCurrentFrame(2);
			break;

		case 3://ũ����
			menu->SetCurrentFrame(3);
			break;

		case 4://���ӼҰ�
			menu->SetCurrentFrame(4);
			break;

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

		case 0://���� ��ŸƮ
			Director::GetInstance()->LoadScene(new Stage1());
			break;

		case 1://���ӹ��
			
			break;

		case 2://��ŷ
			
			break;

		case 3://ũ����
			
			break;

		case 4://���ӼҰ�
			

		case 5:
			
			break;
		}
	}
}

void MainMenu::Render()
{
	Scene::Render();
}
