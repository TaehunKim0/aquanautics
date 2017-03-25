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
	torpedo = new Sprite();
	tripletorpedo = new Sprite();
	missile = new Sprite();

	torpedo->Initialize(L"Resources/UI/Weapon/torpedo.png");
	tripletorpedo->Initialize(L"Resources/UI/Weapon/tripletorpedo.png");
	missile->Initialize(L"Resources/UI/Weapon/missile.png");

	AddChild(torpedo);
	AddChild(tripletorpedo);
	AddChild(missile);

	torpedo->visible = true;
	tripletorpedo->visible = false;
	missile->visible = false;

	SetWeaponType(WeaponType::torpedo);

	return false;
}

void Weapon::Render()
{
	Object::Render();
}

void Weapon::SetWeaponType(WeaponType::Enum type)
{
	weaponType = type;

	switch (weaponType)
	{
	case WeaponType::torpedo:
		torpedo->visible = true;
		tripletorpedo->visible = false;
		missile->visible = false;
		break;

	case WeaponType::tripletorpedo:
		torpedo->visible = false;
		tripletorpedo->visible = true;
		missile->visible = false;
		break;

	case WeaponType::missile:
		torpedo->visible = false;
		tripletorpedo->visible = false;
		missile->visible = true;
		break;
	}

}

WeaponType::Enum Weapon::GetWeaponType()
{
	return weaponType;
}
