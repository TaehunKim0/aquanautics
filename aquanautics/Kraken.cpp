#include "stdafx.h"
#include "Kraken.h"


Kraken::Kraken()
{
}

Kraken::~Kraken()
{
}

bool Kraken::Initialize()
{
	return false;
}

void Kraken::Render()
{
	Object::Render();
}

void Kraken::Update(float deltaTime)
{
	Object::Update(deltaTime);

	m_collision->SetPostion(Position.x, Position.y);
}

void Kraken::IsCollisionWith(Collision * other)
{
}

void Kraken::Attack()
{
}
