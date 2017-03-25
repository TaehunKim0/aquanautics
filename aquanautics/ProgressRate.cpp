#include "stdafx.h"
#include "ProgressRate.h"


ProgressRate::ProgressRate() : middleBoss(0) ,lastBoss(0)
{
}


ProgressRate::~ProgressRate()
{
}

void ProgressRate::Render()
{
	Object::Render();
}

void ProgressRate::Update(float deltaTime)
{
	Object::Update(deltaTime);

	if (GameTime::TotalFrame % 10 == 0)
		progress->Position.x += 1;;

	//�߰� 610
	//���� 965

}

bool ProgressRate::Initialize()
{
	progress = new Sprite();
	progress->Initialize(L"Resources/UI/ProgressRate/progress.png");

	progressbar = new Sprite();
	progressbar->Initialize(L"Resources/UI/ProgressRate/progressbar.png");

	AddChild(progress);
	AddChild(progressbar);

	progressbar->SetPostion(270, 600);
	progress->SetPostion(250, 630);
	
	return false;
}
