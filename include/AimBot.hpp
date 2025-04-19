#pragma once
#include "Coordindates.hpp"
#include "LocalPlayer.hpp"
#include "Entity.hpp"
#include "ViewAngle.hpp"

//class AimBot
//{
//private:
//	CLocalPlayer& localPlayer;
//	std::vector<std::shared_ptr<CEnemy>> enemyList;
//
//private:
//	AimBot();
//	float RadiansToDegrees(float num);
//
//public:
//	static AimBot& GetInstance();
//	std::shared_ptr<CEnemy> GetNearestEnemy();
//	std::shared_ptr<CEnemy>& GetNearestEnemyAngle();
//
//	bool IsInFOV(const Vector3& pos) const;
//	void AimBotMain();
//	ViewAngle& CalcAngle(Vector3& origin, Vector3& target, bool invertYaw = false, bool invertPitch = false);
//};