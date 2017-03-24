#include "stdafx.h"
#include "Player.h"
#include"Bullet.h"

Player::Player() : speed(7.0f)
{
}

Player::~Player()
{
}

bool Player::Initialize()
{
	player = new Sprite();
	player->Initialize(L"Resources/Player/player.png");
	//Player/player

	AddChild(player);
	

	Object::Initialize();

	return true;
}

void Player::Update(float deltaTime)
{
	Object::Update(deltaTime);

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
}

void Player::Render()
{
	Object::Render();
}

void Player::Attack()
{
	
}
