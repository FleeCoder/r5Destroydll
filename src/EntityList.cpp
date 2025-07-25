#include <iostream>
#include "HackMod_Offsets_Cfg.hpp"
#include "HookHandler.hpp"
#include "LocalPlayer.hpp"
#include "EntityList.hpp"
#include "MemoryHandler.hpp"

//std::vector<CEnemy*> CEntity::enemyList;

//CEntityList::CEntityList()
//{
	//HookHandler& hookHandler = HookHandler::GetInstance();
	//EntityBaseAdd = hookHandler.GetExeBaseAddress() + dwEntityListOffset;
	//playersCount = (int*)(*(__int64*)(hookHandler.GetExeBaseAddress() + dwPlayerCountOffset)+0xA10);
	//std::cout << "Player Count: " << *playersCount << std::endl;
//}

//CEntityList& CEntityList::GetInstance()
//{
//	static CEntityList entity;
//	return entity;
//}

//void CEntity::DeleteInstance()
//{
//	for (CEnemy* enemy : enemyList)
//		delete enemy;
//}

//__int64 CEntityList::GetEntityBaseAdd()
//{
//	return EntityBaseAdd;
//}

//const std::vector<std::shared_ptr<CEntity>>& CEntityList::GetEntityList() const
//{
//	return enemyList;
//}

//void CEntity::LoadEnemyList()
//{
//	CLocalPlayer& localPlayer = CLocalPlayer::GetInstance();
//
//	int count = 0;
//	int i = 0;
//	while (count <= *playersCount - 1)
//	{
//		std::shared_ptr<CEnemy> enemy =std::make_shared<CEnemy>(i);
//		if (enemy->GetEnemyBaseAdd() != NULL)
//		{
//			if (enemy->GetEnemyBaseAdd() == localPlayer.GetLocalPlayerBaseAdd())
//			{
//				enemy = nullptr;
//			}
//			else
//			{
//				enemy->LoadEnemyInfo();
//				enemyList.push_back(std::move(enemy));
//			}
//			count++;
//		}
//		i++;
//	}
//}

int GetNumberOfEntities()
{
	OffsetHandler& offsetHandler = OffsetHandler::GetInstance();
	return MemoryHandler::Read<int>(offsetHandler.GetNumEntitiesAddress());
}

constexpr CEntity* CEntityList::GetClientEntity(int entnum) noexcept
{
	return MemoryHandler::Call<CEntity*, int>(this, 4, entnum);
}

void CEntityList::PrintEntityList()
{
	static int noOfPlayers = GetNumberOfEntities();
	std::cout << "Number of entities: " << noOfPlayers << std::endl;
	for (int i = 1;i <= noOfPlayers;i++)
	{
		std::cout << "Entity No: " << i << std::endl;
		GetClientEntity(i)->PrintEnemyInfo();
	}
	//for (int i = 0;i < enemyList.size();i++)
	//{
		//std::cout << "Printing Entity List!!!" << std::endl;
		//std::cout << "**************************************" << std::endl;
		//enemyList[i]->PrintEnemyInfo();
		/*std::cout << "Enemy: " << i + 1 << std::endl;
		std::cout << "----------------------------------" << std::endl;
		std::cout << "Player Health: " << enemyList[i]->GetHealth() << std::endl;
		std::cout << "Player x coordinate: " << enemyList[i]->GetPosition()->x << std::endl;
		std::cout << "Player y coordinate: " << enemyList[i]->GetPosition()->y << std::endl;
		std::cout << "Player z coordinate: " << enemyList[i]->GetPosition()->z << std::endl;*/
	//}
}