#include "stdafx.h"
#include "Weapon.h"


Weapon::Weapon()
{
}


Weapon::~Weapon()
{
}

void Weapon::Update(float deltaTime)
{
	Object::Update(deltaTime);
}

bool Weapon::Initialize()
{



	return false;
}

void Weapon::Render()
{
	Object::Render();
}
