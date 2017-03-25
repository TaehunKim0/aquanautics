#include "stdafx.h"
#include "ItemMgr.h"


ItemMgr::ItemMgr()
{
	itemList.reserve(10);
}


ItemMgr::~ItemMgr()
{
}

void ItemMgr::Update(float deltaTime)
{
	Object::Update(deltaTime);

	for (auto a : itemList)
		a->Update(deltaTime);

}

void ItemMgr::Render()
{
	Object::Render();

	for (auto a : itemList)
		a->Render();
}

bool ItemMgr::Initialize()
{
	return false;
}

void ItemMgr::RegisterItem(Item * item)
{
	itemList.push_back(item);
}
