#pragma once
class Director : public SingleTon<Director>
{
private:
	Scene* CurrentScene;


public:
	Director();
	~Director();

	bool LoadScene(Scene * newScene);

	void Update(float deltaTime);

	void Render();
};

