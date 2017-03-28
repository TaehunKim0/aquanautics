#pragma once
class Hydra : public Object
{
private:
	

public:
	Hydra();
	~Hydra();

	bool Initialize();

	void Release();

	void Render();

	void Update(float deltaTime);
};

