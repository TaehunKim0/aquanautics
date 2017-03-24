#pragma once
class Collision : public Object
{
private:
	

public:
	Collision();
	Collision(D3DXVECTOR3 center , float r);
	~Collision();

	D3DXVECTOR3 Center;
	float radius;

	bool Initialize();
	void Update(float deltaTime);
	void Render();

	bool IsCollideWith(Collision * other);
};