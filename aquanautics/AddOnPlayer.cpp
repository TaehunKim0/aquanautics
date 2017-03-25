#include "stdafx.h"
#include "AddOnPlayer.h"
#include"Torpedo.h"

AddOnPlayer::AddOnPlayer()
{
	Name = "addonplayer";
}

AddOnPlayer::~AddOnPlayer()
{
}

bool AddOnPlayer::Initialize()
{
	player = PlayerMgr::GetInstance()->GetPlayer();

	if (player->IsAddOnPlayer == 1)
	{
		addonplayer = new Sprite();
		addonplayer->Initialize(L"Resources/AddOnPlayer/addonplayer1.png");
	}
	
	if (player->IsAddOnPlayer == 2)
	{
		addonplayer = new Sprite();
		addonplayer->Initialize(L"Resources/AddOnPlayer/addonplayer2.png");
	}
	
	AddChild(addonplayer);
	this->SetPostion(0, -20);
	return false;
}

void AddOnPlayer::Update(float deltaTime)
{
	Object::Update(deltaTime);

	if (GameTime::TotalFrame % 90 == 0)
	{
		Attack();
	}
}

void AddOnPlayer::Render()
{
	Object::Render();
}

void AddOnPlayer::Attack()
{
	auto bullet = new Torpedo();
	bullet->Initialize();
	PRINT(player->IsAddOnPlayer);

	if (player->IsAddOnPlayer == 2)
	{
		auto bullet1 = new Torpedo();
		bullet1->Initialize();

		bullet1->Position.x = (this->Parent->Position.x + 50);
		bullet1->Position.y = (this->Parent->Position.y + 130);

		BulletMgr::GetInstance()->RegisterBullet(bullet1);
		BulletMgr::GetInstance()->Initialize();

	}

	bullet->Position.x = (this->Parent->Position.x);
	bullet->Position.y = (this->Parent->Position.y);

	BulletMgr::GetInstance()->RegisterBullet(bullet);
	BulletMgr::GetInstance()->Initialize();
}
