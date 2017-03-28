#include "stdafx.h"
#include "Hydra.h"


Hydra::Hydra()
{
	Name = "hydra";
}

Hydra::~Hydra()
{
}

bool Hydra::Initialize()
{


	return false;
}

void Hydra::Release()
{
	
}

void Hydra::Render()
{
	Object::Render();
}

void Hydra::Update(float deltaTime)
{
	Object::Update(deltaTime);
}
