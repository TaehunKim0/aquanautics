#include "stdafx.h"
#include "Player.h"
#include"Torpedo.h"
#include"Weapon.h"
#include"TripleBullet.h"

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
	player = new Sprite();
	player->Initialize(L"Resources/Player/player.png");
	m_collision = new Collision(this->player->Center, 100, this);


	life = new AnimationSprite(4, 10);
	life->AddFrame(Sprite::Create(L"Resources/UI/Life/1.png"));
	life->AddFrame(Sprite::Create(L"Resources/UI/Life/2.png"));
	life->AddFrame(Sprite::Create(L"Resources/UI/Life/3.png"));
	life->AddFrame(Sprite::Create(L"Resources/UI/Life/4.png"));
	life->AddFrame(Sprite::Create(L"Resources/UI/Life/5.png"));
	life->SetCurrentFrame(4);
	life->AutoNext = false;
	life->SetPostion(50, 30);

	weapon = new Weapon();
	weapon->SetPostion(610, 70);
	weapon->Initialize();
	//weapon->SetWeaponType(WeaponType::tripletorpedo);

	nuclear = new AnimationSprite(2, 10);
	nuclear->AddFrame(Sprite::Create(L"Resources/UI/Weapon/nuclear1.png"));
	nuclear->AddFrame(Sprite::Create(L"Resources/UI/Weapon/nuclear2.png"));
	nuclear->AddFrame(Sprite::Create(L"Resources/UI/Weapon/nuclear3.png"));
	nuclear->SetCurrentFrame(0);
	nuclear->AutoNext = false;
	nuclear->SetPostion(690, 100);

	AddChild(player);

	Object::Initialize();

	return true;

}

void Player::Update(float deltaTime)
{
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
		collisionTime++;

		if (collisionTime == 360)
		{
			Cancollision = true;
			collisionTime = 0;
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

void Player::Attack()
{
	if (Input::IsKeyDown(VK_SPACE) && GameTime::CurrentFrame % 10 == 0)
	{
		if (weapon->GetWeaponType() == WeaponType::torpedo)
		{
			auto bullet = new Torpedo();
			bullet->Position.x += (this->Position.x) + (player->Texture->Size.x / 2) + 55;
			bullet->Position.y += (this->Position.y) + (player->Texture->Size.y / 2) + 29;

			BulletMgr::GetInstance()->RegisterBullet(bullet);
			BulletMgr::GetInstance()->Initialize();
		}
	
		if (weapon->GetWeaponType() == WeaponType::tripletorpedo)
		{
			auto bullet = new TripleBullet(30.0f);
			bullet->Position.x += (this->Position.x) + (player->Texture->Size.x / 2) + 55;
			bullet->Position.y += (this->Position.y) + (player->Texture->Size.y / 2) + 29;

			BulletMgr::GetInstance()->RegisterBullet(bullet);
			BulletMgr::GetInstance()->Initialize();

			auto bullet1 = new TripleBullet(-30.0f);
			bullet1->Position.x += (this->Position.x) + (player->Texture->Size.x / 2) + 55;
			bullet1->Position.y += (this->Position.y) + (player->Texture->Size.y / 2) + 29;

			BulletMgr::GetInstance()->RegisterBullet(bullet1);
			BulletMgr::GetInstance()->Initialize();

			auto bullet2 = new Torpedo();
			bullet2->Position.x += (this->Position.x) + (player->Texture->Size.x / 2) + 55;
			bullet2->Position.y += (this->Position.y) + (player->Texture->Size.y / 2) + 29;

			BulletMgr::GetInstance()->RegisterBullet(bullet2);
			BulletMgr::GetInstance()->Initialize();
		}

	}

	if (Input::IsKeyDown(VK_LSHIFT))
	{

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

	if (Position.x >= WINDOW_WIDTH - player->Texture->Size.x)
		Position.x = WINDOW_WIDTH - player->Texture->Size.x;

	if (Position.x <= 0)
		Position.x = 0;

	if (Position.y>= WINDOW_HEIGHT - player->Texture->Size.y)
		Position.y = WINDOW_HEIGHT - player->Texture->Size.y;

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

		if (other->Parent->Name == "speedup")
		{
			speed += 50;
			Cancollision = 0;
		}
	}
}
