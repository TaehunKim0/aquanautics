#pragma once
class EnemySpawner : public Object , public SingleTon<EnemySpawner>
{
private:
	std::vector<Object*>enemyList;


public:
	EnemySpawner();
	~EnemySpawner();

	bool Initialize();
	void Update(float deltaTime);
	void Render();

	void SpawnEnemy(int x, int y);

};

