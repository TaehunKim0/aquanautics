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
	void SpawnShark(int x, int y);
	void SpawnKraken(int x, int y);
};