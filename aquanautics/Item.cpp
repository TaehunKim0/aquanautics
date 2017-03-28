#include "stdafx.h"
#include "Item.h"


Item::Item(int x, int y)
{
	SetPostion(x, y);

	ItemMgr::GetInstance()->RegisterItem(this);

	id = 1;
}


Item::~Item()
{
}

void Item::Update(float deltaTime)
{
	Object::Update(deltaTime);
	if(m_collision !=nullptr)
		m_collision->SetPostion(Position.x, Position.y);

	Position.x -= 1;

}

void Item::Render()
{
	Object::Render();
}

bool Item::Initialize()
{
	int ra = 0;
	srand(time(NULL));
	ra = (rand() % 5) + 1;

	switch (ra)
	{
	case 0: //�ֵ�� �÷��̾�0
	{
		auto sprite = Sprite::Create(L"Resources/Item/addonplayer.png");
		AddChild(sprite);
		m_collision = new Collision(sprite->Center, 30, this);

		this->Name = "addonplayer";
	}
	
		break;
	case 1: //3 ����0
	{
		auto sprite = Sprite::Create(L"Resources/Item/tripletorpedo.png");
		AddChild(sprite);
		m_collision = new Collision(sprite->Center, 30, this);

		this->Name = "tripletorpedo";
	}
		break;

	case 2: //��ź��
	{
		auto sprite = Sprite::Create(L"Resources/Item/recovery.png");
		AddChild(sprite);
		m_collision = new Collision(sprite->Center, 30, this);

		this->Name = "nuclear";
	}
		break;

	case 3: // ����
	{
		auto sprite = Sprite::Create(L"Resources/Item/missile.png");
		AddChild(sprite);
		m_collision = new Collision(sprite->Center, 30, this);

		this->Name = "missile";
	}
		break;

	case 4: //ȸ��0
	{
		auto sprite = Sprite::Create(L"Resources/Item/recovery.png");
		AddChild(sprite);
		m_collision = new Collision(sprite->Center, 30, this);

		this->Name = "recovery";
	}
		break;

	case 5: //���ǵ��0
	{
		auto sprite = Sprite::Create(L"Resources/Item/speedup.png");
		AddChild(sprite);
		
		this->Name = "speedup";
		m_collision = new Collision(sprite->Center, 30, this);
	}
		break;

	default:
		break;

	}

	//printf("Item : %s ����\n", Name);

	return true;
}

void Item::IsCollisionWith(Collision * other)
{
	if (other->Parent->Name == "player")
	{
		this->visible = false;

		printf("Player Collision - item\n");
	}

}
