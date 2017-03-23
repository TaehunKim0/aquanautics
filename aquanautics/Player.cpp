#include "stdafx.h"
#include "Player.h"
#include"Bullet.h"

Player::Player()
{
}

Player::~Player()
{
}

bool Player::Initialize()
{
	player = new Sprite();
	player->Initialize(L"Resources/Player/player.png");


	AddChild(player);
	

	Object::Initialize();

	return true;
}

void Player::Update(float deltaTime)
{
	Object::Update(deltaTime);

	if (Input::IsKeyDown(VK_LEFT))
		Position.x -= 10;
	
	if (Input::IsKeyDown(VK_RIGHT))
		Position.x += 10;

	if (Input::IsKeyDown(VK_UP))
		Position.y -= 10;

	if (Input::IsKeyDown(VK_DOWN))
		Position.y += 10;

	if (Input::IsKeyDown(VK_SPACE) && GameTime::CurrentFrame % 20 == 0)
	{
		auto bullet = new Bullet();
		bullet->Position.x = this->player->Position.x + player->Texture->Size.x / 2;
		bullet->Position.y = this->player->Position.y + player->Texture->Size.y / 2;

		BulletMgr::GetInstance()->RegisterBullet(bullet);
		BulletMgr::GetInstance()->Initialize();
	}

	printf("x : %d", Position.x);
	printf("y : %d", Position.y);
}

void Player::Render()
{
	Object::Render();
}

void Player::Attack()
{
	
}
