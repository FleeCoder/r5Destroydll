#pragma once
#include "Coordindates.hpp"

class CEntity
{
//private:
	//__int64 enemyBaseAdd;
	//int* health;
	//Vector3* position;

public:
	//CEntity(int index);
	//CEntity(CEntity& enemy);
	//CEntity(CEntity&& enemy);

	//CEntity& operator=(const CEntity& enemy);

	//__int64 GetEnemyBaseAdd();
	int GetHealth();
	//Vector3* GetPosition();

	//bool IsDead();
	//void LoadEnemyInfo();
	void PrintEnemyInfo();
};