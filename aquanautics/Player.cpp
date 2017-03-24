#include "stdafx.h"
#include "Player.h"
#include"Bullet.h"

Player::Player() : speed(7.0f)
{
	id = 12;
	Name = "player";
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
	m_collision = new Collision(this->player->Center , 100, this);



	Object::Initialize();

	return true;
}

void Player::Update(float deltaTime)
{
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
}

void Player::Render()
{
	Object::Render();
}

void Player::Attack()
{
	
}

void Player::IsCollisionWith(Collision * other)
{
	if (other->Parent->Name == "urak")
		printf("Player - Urak Collide\n");
}
