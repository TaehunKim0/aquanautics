#pragma once
class Scene;
class Director : public SingleTon<Director>
{
public:
	Scene* CurrentScene;


public:
	Director();
	~Director();

	bool LoadScene(Scene * newScene);

	void Update(float deltaTime);

	void Render();
};

