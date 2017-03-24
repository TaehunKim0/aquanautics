#include"stdafx.h"
#include "Object.h"


Object::Object(std::string name) : Name(name), Parent(nullptr), Position(0.f, 0.f) , Rotation(0.f) ,visible(1) ,id(0)
{
	printf("Object %s 积己凳\n", Name.c_str());
}


Object::~Object()
{
	for each(auto child in Children)
		SAFE_DELETE(child);

	Children.clear();

	printf("Object %s 家戈凳\n", Name.c_str());

}

void Object::SetPostion(int x, int y)
{
	Position.x = x;
	Position.y = y;
}

bool Object::Initialize()
{
	for each(auto child in Children)
		child->Initialize();

	return true;
}

void Object::Release()
{
	for each(auto child in Children)
		child->Release();

	printf("Object %s 副府令凳\n", Name.c_str());

}

void Object::Update(float deltaTime)
{
	if (!visible)
		return;

	D3DXMatrixTransformation2D(&Matrix, NULL, 0.0f, NULL, NULL, Rotation, &Position);

	if (Parent)
		Matrix *= Parent->Matrix;

	for each(auto child in Children)
		child->Update(deltaTime);

}

void Object::Render()
{
	if (!visible)
		return;

	for each(auto child in Children)
		child->Render();
}

void Object::IsCollisionWith(Collision * collision)
{
}

void Object::AddChild(Object * child)
{
	child->Parent = this;
	Children.push_back(child);
}
