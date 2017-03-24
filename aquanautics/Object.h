#pragma once
class Collision;
class Object
{
public:
	Object* Parent;
	std::vector<Object*> Children;

	std::string Name;

	D3DXVECTOR2 Position;
	FLOAT Rotation;

	D3DXMATRIX Matrix;

	bool visible;

	int id;
public:
	Object(std::string name = "");
	~Object();

	void SetPostion(int x, int y);

	virtual bool Initialize();

	virtual void Release();

	virtual void Update(float deltaTime);

	virtual void Render();

	virtual void IsCollisionWith(Collision* collision);

public:
	void AddChild(Object* child);

	bool GetVisisble() { return visible; }
	void SetVisible(bool visible) { this->visible = visible; }
};

