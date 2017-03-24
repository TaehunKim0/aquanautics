#include "stdafx.h"
#include "Player.h"
#include"Bullet.h"

Player::Player() : speed(7.0f) , lifeCount(4)
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

	life = new AnimationSprite(3, 10);
	
	life->AddFrame(Sprite::Create(L"Resources/UI/Life/1.png"));
	life->AddFrame(Sprite::Create(L"Resources/UI/Life/2.png"));
	life->AddFrame(Sprite::Create(L"Resources/UI/Life/3.png"));
	life->AddFrame(Sprite::Create(L"Resources/UI/Life/4.png"));
	life->SetCurrentFrame(0);

	life->AutoNext = false;

	AddChild(player);
	
	life->SetPostion(50, 50);

	m_collision = new Collision(this->player->Center , 100, this);

	Object::Initialize();

	return true;
}

void Player::Update(float deltaTime)
{
	if (lifeCount > 0)
		life->Update(deltaTime);
	

	Object::Update(deltaTime);
	m_collision->SetPostion(Position.x, Position.y);

	if (Input::IsKeyDown(VK_LEFT))
		Position.x -= speed;
	
	if (Input::IsKeyDown(VK_RIGHT))
		Position.x += speed;

	if (Input::IsKeyDown(VK_UP))
		Position.y -= speed;

	if (Input::IsKeyDown(VK_DOWN))
		Position.y += speed;

	if (Input::IsKeyDown(VK_SPACE) && GameTime::CurrentFrame % 10 == 0)
	{
 		auto bullet = new Bullet();
		bullet->Position.x += (this->Position.x) +(player->Texture->Size.x / 2 ) + 55;
		bullet->Position.y += (this->Position.y) + (player->Texture->Size.y / 2) + 29;

		BulletMgr::GetInstance()->RegisterBullet(bullet);
		BulletMgr::GetInstance()->Initialize();
	}

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
	}

	

}

void Player::Render()
{
	Object::Render();

	if (lifeCount > 0)
		life->Render();
	
	
}

void Player::Attack()
{
	
}

void Player::IsCollisionWith(Collision * other)
{
	if (other->Parent->Name == "urak")
	{
		lifeCount -= 1;

		//3초간 무적
	}
}
