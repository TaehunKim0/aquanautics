#include "stdafx.h"
#include "PlayerMgr.h"
#include"Player.h"

PlayerMgr::PlayerMgr()
{
	player = new Player();
	printf("Player »ý¼º \n");
}


PlayerMgr::~PlayerMgr()
{
	
}

Player * PlayerMgr::GetPlayer()
{
	return player;
}
