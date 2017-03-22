#pragma once
#include"Object.h"
class Scene : public Object
{
public:
	Scene();
	virtual ~Scene();

	void Release() {};

	void Update(float deltaTime) {};

	void Render() {};
};

