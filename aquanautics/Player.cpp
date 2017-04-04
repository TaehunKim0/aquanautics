#include "stdafx.h"
#include "Player.h"
#include"Torpedo.h"
#include"Weapon.h"
#include"TripleBullet.h"
#include"AddOnPlayer.h"
#include"MainMenu.h"

Player::Player() : speed(7.0f) , lifeCount(5) , collisionTime(0) ,Cancollision(1) , IsAddOnPlayer(0)
{
	id = 12;
	Name = "player";
	SetPostion(200, 200);
}

Player::~Player()
{
}

bool Player::Initialize()
{
	player = new AnimationSprite(1,10);
	player->AddFrame(Sprite::Create(L"Resources/Player/player.png"));
	player->AddFrame(Sprite::Create(L"Resources/Player/isplayercollide.png"));
	player->AutoNext = false;
	player->SetCurrentFrame(0);

	m_collision = new Collision(this->player->Center, 100, this);
	AddChild(m_collision);
	//
	life = new AnimationSprite(4, 10);
	life->AddFrame(Sprite::Create(L"Resources/UI/Life/1.png"));
	life->AddFrame(Sprite::Create(L"Resources/UI/Life/2.png"));
	life->AddFrame(Sprite::Create(L"Resources/UI/Life/3.png"));
	life->AddFrame(Sprite::Create(L"Resources/UI/Life/4.png"));
	life->AddFrame(Sprite::Create(L"Resources/UI/Life/5.png"));
	life->SetCurrentFrame(4);
	life->AutoNext = false;
	life->SetPostion(50, 30);
	//
	weapon = new Weapon();
	weapon->SetPostion(610, 70);
	weapon->Initialize();

	weapon->SetWeaponType(WeaponType::torpedo);
	//
	nuclear = new AnimationSprite(2, 10);
	nuclear->AddFrame(Sprite::Create(L"Resources/UI/Weapon/nuclear1.png"));
	nuclear->AddFrame(Sprite::Create(L"Resources/UI/Weapon/nuclear2.png"));
	nuclear->AddFrame(Sprite::Create(L"Resources/UI/Weapon/nuclear3.png"));
	nuclear->SetCurrentFrame(0);
	nuclear->AutoNext = false;
	nuclear->SetPostion(690, 100);
	//
	
	AddChild(player);

	Object::Initialize();

	return true;



}

void Player::Update(float deltaTime)
{
	Cheat();

	if (lifeCount > 0)
		life->Update(deltaTime);
	
	weapon->Update(deltaTime);
	nuclear->Update(deltaTime);


	Object::Update(deltaTime);	
	m_collision->SetPostion(Position.x, Position.y);

	Move();

	Attack();

	switch (lifeCount)
	{
	case 1:
		life->SetCurrentFrame(0);
		break;

	case 2:
		life->SetCurrentFrame(1);
		break;

	case 3:
		life->SetCurrentFrame(2);
		break;

	case 4:
		life->SetCurrentFrame(3);
		break;

	case 5:
		life->SetCurrentFrame(4);
		break;
	}

	if (!Cancollision)
	{
		player->SetCurrentFrame(1);

		collisionTime++;

		if (collisionTime == 60)
		{
			Cancollision = true;
			collisionTime = 0;
			player->SetCurrentFrame(0);
		}

	}

}

void Player::Render()
{
	Object::Render();

	if (lifeCount > 0)
		life->Render();

	weapon->Render();
	nuclear->Render();
}

void Player::Release()
{
	printf("Player Release\n");

	Object::Release();
}

void Player::Attack()
{
	if (Input::IsKeyDown(VK_SPACE) && GameTime::CurrentFrame % 20 == 0)
	{
		if (weapon->GetWeaponType() == WeaponType::torpedo)
		{
			auto bullet0 = new Torpedo();
			bullet0->Initialize();
			bullet0->UseParentMatrix = false;
			bullet0->Position.x += (this->Position.x) + (player->GetCurrentFrame()->Texture->Size.x / 2) + 55;
			bullet0->Position.y += (this->Position.y) + (player->GetCurrentFrame()->Texture->Size.y / 2) + 29;
	
			AddChild(bullet0);
		}
	
		if (weapon->GetWeaponType() == WeaponType::tripletorpedo)
		{
			auto bullet2 = new Torpedo();
			bullet2->Initialize();
			bullet2->UseParentMatrix = false;
			bullet2->Position.x += (this->Position.x) + (player->GetCurrentFrame()->Texture->Size.x / 2) + 55;
			bullet2->Position.y += (this->Position.y) + (player->GetCurrentFrame()->Texture->Size.y / 2) + 29;
			AddChild(bullet2);

			auto bullet = new TripleBullet(60.0f);
			bullet->Initialize();
			bullet->UseParentMatrix = false;
			bullet->Position.x += (this->Position.x) + (player->GetCurrentFrame()->Texture->Size.x / 2) + 55;
			bullet->Position.y += (this->Position.y) + (player->GetCurrentFrame()->Texture->Size.y / 2) + 29;
			AddChild(bullet);

			auto bullet1 = new TripleBullet(-60.0f);
			bullet1->Initialize();
			bullet1->UseParentMatrix = false;
			bullet1->Position.x += (this->Position.x) + (player->GetCurrentFrame()->Texture->Size.x / 2) + 55;
			bullet1->Position.y += (this->Position.y) + (player->GetCurrentFrame()->Texture->Size.y / 2) + 29;

			AddChild(bullet1);
		}

	}


}

void Player::Move()
{
	if (Input::IsKeyDown(VK_LEFT))
		Position.x -= speed;

	if (Input::IsKeyDown(VK_RIGHT))
		Position.x += speed;

	if (Input::IsKeyDown(VK_UP))
		Position.y -= speed;

	if (Input::IsKeyDown(VK_DOWN))
		Position.y += speed;

	if (Position.x >= WINDOW_WIDTH - player->GetCurrentFrame()->Texture->Size.x)
		Position.x = WINDOW_WIDTH - player->GetCurrentFrame()->Texture->Size.x;

	if (Position.x <= 0)
		Position.x = 0;

	if (Position.y>= WINDOW_HEIGHT - player->GetCurrentFrame()->Texture->Size.y)
		Position.y = WINDOW_HEIGHT - player->GetCurrentFrame()->Texture->Size.y;

	if (Position.y <= 0)
		Position.y = 0;
}

void Player::IsCollisionWith(Collision * other)
{
	if (Cancollision)
	{
		if (other->Parent->Name == "urak")
		{
			lifeCount--;
			Cancollision = 0;
		}

		if (other->Parent->Name == "shark")
		{
			lifeCount--;
			Cancollision = 0;
		}

	}

	if (other->Parent->Name == "addonplayer")
	{
		IsAddOnPlayer++;
		if (IsAddOnPlayer == 3)
			return;

		auto addon = new AddOnPlayer();
		addon->Initialize();

		AddChild(addon);
		Cancollision = 0;
	}

	if (other->Parent->Name == "speedup")
		speed += 1;

	if (other->Parent->Name == "tripletorpedo")
		weapon->SetWeaponType(WeaponType::tripletorpedo);

	if (other->Parent->Name == "recovery")
	{
		if (lifeCount < 5)
			lifeCount++;

		else
			return;
	}

	if (other->Parent->Name == "enemybullet")
		lifeCount--;

}

void Player::Cheat()
{
	if (Input::IsKeyDown(VK_F1))
		return;

	if (Input::IsKeyDown(VK_F2))
		weapon->SetWeaponType(WeaponType::tripletorpedo);

	if (Input::IsKeyDown(VK_F3))
		weapon->SetWeaponType(WeaponType::missile);




	if (Input::IsKeyDown('I'))
		IsAddOnPlayer = 2;

	if (Input::IsKeyDown(VK_F7))
	{
		IsAddOnPlayer++;

		if (IsAddOnPlayer < 3)
		{
			if (IsAddOnPlayer == 2)
			{
				auto addon = new AddOnPlayer();
				addon->Initialize();
				addon->SetPostion(50, 130);
				AddChild(addon);

				return;
			}

			auto addon = new AddOnPlayer();
			addon->Initialize();

			AddChild(addon);
		}
	}
}
