#pragma once
class Urak : public Object
{
private:
	Sprite* urak;

	Collision* m_collision;

	int speed;
public:
	Urak();
	~Urak();

	bool Initialize();
	void Update(float deltaTime);
	void Render();

	void IsCollisionWith(Collision* collision);

};