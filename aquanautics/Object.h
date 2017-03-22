#pragma once
class Object
{
public:
	Object* Parent;
	std::vector<Object*> Children;

	std::string Name;

	D3DXVECTOR2 Position;
	FLOAT Rotation;

	D3DXMATRIX Matrix;

public:
	Object(std::string name = "");
	~Object();

	virtual bool Initialize();

	virtual void Release();

	virtual void Update(float deltaTime);

	virtual void Render();

public:
	void AddChild(Object* child);

};

