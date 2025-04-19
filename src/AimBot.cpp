#include <limits>
#include <math.h>
#include <iostream>
#include "AimBot.hpp"
#include "Coordindates.hpp"

constexpr auto PI = 3.1415927f;

//AimBot::AimBot():localPlayer(CLocalPlayer::GetInstance()),enemyList(CEntity::GetInstance().GetEntityList())
//{
//	//CEntity::GetInstance().PrintEntityList();
//}
//
//AimBot& AimBot::GetInstance()
//{
//	static AimBot aimBot;
//	return aimBot;
//}
//
//bool AimBot::IsInFOV(const Vector3& pos) const
//{
//	return true;
//}
//
//std::shared_ptr<CEnemy> AimBot::GetNearestEnemy()
//{
//	std::shared_ptr<CEnemy> nearestPlayer;
//	float nearestDistance = FLT_MAX;
//	for (int enemy = 0;enemy < enemyList.size();enemy++)
//	{
//		/*std::cout << "Enemy: " << enemy << std::endl;
//		std::cout << "-----------------------------" << std::endl;
//		enemyList[enemy]->PrintEnemyInfo();*/
//		//std::cout << "1" << std::endl;
//		if (enemyList[enemy]->IsDead() || !IsInFOV(*(enemyList[enemy]->GetPosition())))
//			continue;
//		//std::cout << "2" << std::endl;
//		float distance = localPlayer.GetPosition()->Distance(*(enemyList[enemy]->GetPosition()));
//		////std::cout << "distance: " << distance << std::endl;
//		if (distance < nearestDistance)
//		{
//			nearestDistance = distance;
//			nearestPlayer = enemyList[enemy];
//		}
//	}
//	//std::cout << "-----------------------Nearest Player-----------------------" << std::endl;
//	//nearestPlayer->PrintEnemyInfo();
//	return nearestPlayer;
//}
//
//ViewAngle& AimBot::CalcAngle(Vector3& origin, Vector3& target, bool invertYaw, bool invertPitch)
//{
//	ViewAngle results;
//	/*std::cout << "Player" << std::endl;
//	std::cout << "-------------------------------" << std::endl;
//	origin.PrintCoordinates();
//	std::cout << "Target" << std::endl;
//	std::cout << "-------------------------------" << std::endl;
//	target.PrintCoordinates();*/
//	//std::cout << "1" << std::endl;
//	Vector3 delta = target - origin; // Get the difference between the two vectors
//
//	////std::cout << "2" << std::endl;
//	float distance = origin.Distance(target);
//	if (distance == 0.0f) // Prevent division by zero
//		return results;
//
//	float yawSign = invertYaw ? -1.0f : 1.0f;
//	float pitchSign = invertPitch ? -1.0f : 1.0f;
//
//	////std::cout << "3" << std::endl;
//	results.yaw=yawSign * RadiansToDegrees(atan2f(delta.y, delta.x));
//	results.pitch=pitchSign * RadiansToDegrees(asinf((delta.z) / distance));
//	//std::cout << "-------------------------------------" << std::endl;
//	//std::cout << "Yaw: " << results.yaw << std::endl;
//	//std::cout << "Pitch: " << results.pitch << std::endl;
//	return results;
//}
//
//float AimBot::RadiansToDegrees(float num)
//{
//	return num / PI * 180.0f;
//}
//
//void AimBot::AimBotMain()
//{
//	if (!GetAsyncKeyState(VK_CAPITAL))
//		return;
//	//std::cout << "1" << std::endl;
//	std::shared_ptr<CEnemy> targetLock = GetNearestEnemy();
//	if (!targetLock)
//		return;
//	//std::cout << "-----------------------Nearest Player Recieved-----------------------" << std::endl;
//	//targetLock->PrintEnemyInfo();
//	//std::cout << "2" << std::endl;
//	ViewAngle angle = CalcAngle(*localPlayer.GetPosition(), *targetLock->GetPosition(), false, true);
//	//std::cout << "3" << std::endl;
//	//std::cout << "Angle Calculated Successfuly!!!" << std::endl;
//	//std::cout << "Yaw: " << angle.yaw << std::endl;
//	//std::cout << "Pitch: " << angle.pitch << std::endl;
//	localPlayer.GetCameraViewAngle()->yaw = angle.yaw;
//	localPlayer.GetCameraViewAngle()->pitch = angle.pitch;
//	//std::cout << "End of Aim Bot Main Function !!!" << std::endl;
//}

//std::shared_ptr<CEnemy>& GetNearestEnemyAngle()
//{
//	Vector3 playe
//}