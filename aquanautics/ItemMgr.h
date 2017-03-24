#pragma once
class Item;
class ItemMgr : public Object, public SingleTon<ItemMgr>
{
	std::vector<Item*> itemList;

public:
	ItemMgr();
	~ItemMgr();

	void Update(float deltaTime);
	void Render();
	bool Initialize();

	void RegisterItem(Item* item);
};

