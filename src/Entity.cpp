#include "HackMod_Offsets_Cfg.hpp"
#include "Entity.hpp"
#include <iostream>
//#include "OffsetHandler.hpp"
#include "NetVarManager.hpp"
#include "MemoryHandler.hpp"

//CEntity::CEntity(int index):health(nullptr),position(nullptr)
//{
//	CEntity& entity = CEntity::GetInstance();
//	__int64 entityBaseAdd = entity.GetEntityBaseAdd();
//	//std::cout << "Entity Base Address: " << entityBaseAdd << "\tNext Player Address: " << entityBaseAdd + index * dwEntityPlayerOffset << std::endl;
//	enemyBaseAdd = *(__int64*)(entityBaseAdd + index*dwEntityPlayerOffset);
//	//std::cout << "Enemy Base Address: " << enemyBaseAdd << std::endl;
//}

//CEntity::CEntity(CEntity& enemy):enemyBaseAdd(enemy.enemyBaseAdd),health(enemy.health),position(enemy.position)
//{
//
//}
//
//CEntity::CEntity(CEntity&& enemy)
//{
//	enemyBaseAdd = enemy.enemyBaseAdd;
//	health = enemy.health;
//	position = enemy.position;
//	enemy.enemyBaseAdd = NULL;
//	enemy.health = nullptr;
//	enemy.position = nullptr;
//}
//
//CEntity& CEntity::operator=(const CEntity& enemy)
//{
//	this->enemyBaseAdd = enemy.enemyBaseAdd;
//	this->health = enemy.health;
//	this->position = enemy.position;
//	return *this;
//}
//
//__int64 CEntity::GetEnemyBaseAdd()
//{
//	return enemyBaseAdd;
//}

int CEntity::GetHealth()
{
	if (!this)
		return NULL;
	NetVarManager& netVarManager = NetVarManager::GetInstance();
	static DWORD64 healthOff = netVarManager.GetNetVarOffset("DT_Player", "m_iHealth");
	std::cout << "health offset: " << healthOff << std::endl;
	return MemoryHandler::Read<int>((DWORD64)this + healthOff);
}

//Vector3* CEntity::GetPosition()
//{
//	return position;
//}
//
//bool CEntity::IsDead()
//{
//	if (*health <= 0)
//	{
//		return true;
//	}
//	else
//	{
//		return false;
//	}
//}
//
//void CEntity::LoadEnemyInfo()
//{
//	health = (int*)(enemyBaseAdd + dwHealthOffset);
//	position = (Vector3*)(enemyBaseAdd + dwPlayerPositionOffset);
//}

void CEntity::PrintEnemyInfo()
{
	if (!this)
		return;
	std::cout << "Health: " << GetHealth() << std::endl;
	/*std::cout << "------------------------------------------" << std::endl;
	std::cout << "Enemy Base Add: " << enemyBaseAdd << std::endl;
	std::cout << "Player Health: " << *health << std::endl;
	std::cout << "Player x coordinate: " << position->x << std::endl;
	std::cout << "Player y coordinate: " << position->y << std::endl;
	std::cout << "Player z coordinate: " << position->z << std::endl;*/
}