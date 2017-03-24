#pragma once
class AddOnPlayer : public Object
{
private:


public:
	AddOnPlayer();
	~AddOnPlayer();

	bool Initialize();
	void Update(float deltaTime);
	void Render();


};

