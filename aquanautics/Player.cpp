#include "stdafx.h"
#include "Player.h"

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
}

void Player::Render()
{
	Object::Render();
}
