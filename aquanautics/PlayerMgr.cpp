#include "stdafx.h"
#include "PlayerMgr.h"
#include"Player.h"

PlayerMgr::PlayerMgr()
{
	player = new Player();
	printf("Player ���� \n");
}


PlayerMgr::~PlayerMgr()
{
	
}

Player * PlayerMgr::GetPlayer()
{
	return player;
}
