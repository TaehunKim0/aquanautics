#pragma once
namespace WeaponType
{
	enum Enum
	{
		torpedo = 0,
		tripletorpedo = 1,
		missile = 2
	};
}

class Weapon : public Object
{
private:
	Sprite* torpedo;
	Sprite* missile;
	Sprite* tripletorpedo;
	

public:
	Weapon();
	~Weapon();

	void Update(float deltaTime);
	bool Initialize();
	void Render();

public:
	WeaponType::Enum weaponType;

	void SetWeaponType(WeaponType::Enum type);

	WeaponType::Enum GetWeaponType();
};