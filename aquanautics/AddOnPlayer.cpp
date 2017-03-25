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

	if (!player->IsAddOnPlayer)
	{
		addonplayer = new Sprite();
		addonplayer->Initialize(L"Resources/AddOnPlayer/addonplayer1.png");
	}
	
	if (player->IsAddOnPlayer)
	{
		addonplayer = new Sprite();
		addonplayer->Initialize(L"Resources/AddOnPlayer/addonplayer2.png");
	}
	


	AddChild(addonplayer);

	return false;
}

void AddOnPlayer::Update(float deltaTime)
{
	Object::Update(deltaTime);
}

void AddOnPlayer::Render()
{
	Object::Render();
}

void AddOnPlayer::Attack()
{

	if (GameTime::TotalFrame % 90 == 0)
	{
		auto bullet = new Torpedo();
		bullet->Position.x += (this->Position.x) + (addonplayer->Texture->Size.x / 2) ;
		bullet->Position.y += (this->Position.y) + (addonplayer->Texture->Size.y / 2) ;

		BulletMgr::GetInstance()->RegisterBullet(bullet);
		BulletMgr::GetInstance()->Initialize();

	}

}
