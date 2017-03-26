#include "stdafx.h"
#include "ProgressRate.h"


ProgressRate::ProgressRate() : middleBoss(0) ,lastBoss(0)
{
}


ProgressRate::~ProgressRate()
{

	printf("ProgressRate Release\n");
	SAFE_RELEASE(progress);
	SAFE_RELEASE(progressbar);

	
}

void ProgressRate::Render()
{
	Object::Render();
}

void ProgressRate::Update(float deltaTime)
{
	Object::Update(deltaTime);


	if (!(middleBoss | lastBoss))
	{
		if (GameTime::TotalFrame % 10 == 0)
			progress->Position.x += 1;
	}
	
	if (progress->Position.x == 610)
		middleBoss = 1;

	if (progress->Position.x == 965)
		lastBoss = 1;

	//중간 610
	//최종 965

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
