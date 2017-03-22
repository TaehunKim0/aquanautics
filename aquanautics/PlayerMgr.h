#pragma once
class Player;
class PlayerMgr : public SingleTon<PlayerMgr>
{
private:
	Player* player;

public:
	PlayerMgr();
	~PlayerMgr();

	Player* GetPlayer();
};

