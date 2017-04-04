#include"stdafx.h"
#include "Object.h"

Object::Object() : Parent(nullptr), Position(0.f, 0.f) , Rotation(0.f) ,visible(1) ,id(0) , UseParentMatrix(1)
{
	//printf("Object %s 积己凳\n", Name.c_str());+		[allocator]	allocator	std::_Compressed_pair<std::_Wrap_alloc<std::allocator<Object *> >,std::_Vector_val<std::_Simple_types<Object *> >,1>

}

Object::~Object()
{
	for each(auto child in Children)
	{
		if(child)
			SAFE_DELETE(child);
	}

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
		if(UseParentMatrix)
			Matrix *= Parent->Matrix;

	while (!DestroyList.empty())
	{
		RemoveChild(DestroyList.front() , true);
		DestroyList.pop();
	}

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

void Object::IsCollisionWith(Object * collision)
{
}

void Object::AddChild(Object * child)
{
	child->Parent = this;
	Children.push_back(child);
}

void Object::RemoveChild(Object* child , bool memorydelete)
{

	auto iterator = std::find(std::begin(Children), std::end(Children), child);
	if (iterator == Children.end())
		return;
		
	Children.erase(iterator);

	if (memorydelete)
	{
		child->Release();
		SAFE_DELETE(child);
		return;
	}

	child->Parent = nullptr;
}