#pragma once
class Collision;
class Object
{
public:
	Object* Parent;
	std::vector<Object*> Children;
	std::queue<Object*> DestroyList;
	std::string Name;

	D3DXVECTOR2 Position;
	FLOAT Rotation;

	D3DXMATRIX Matrix;

	bool visible;

	int id;
	bool UseParentMatrix;

	Collision* m_collision;

public:
	Object();
	~Object();

	void SetPostion(int x, int y);

	virtual bool Initialize();

	virtual void Release();

	virtual void Update(float deltaTime);

	virtual void Render();

	virtual void IsCollisionWith(Object* collision);

	virtual void Destroy()
	{
		if (Parent)
			Parent->DestroyList.push(this);
	}

public:
	void AddChild(Object* child);

	bool GetVisisble() { return visible; }
	void SetVisible(bool visible) { this->visible = visible; }

	void RemoveChild(Object* child, bool memorydelete);
};

