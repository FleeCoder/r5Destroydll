#pragma once
#include <Windows.h>
#include <vector>
#include "Coordindates.hpp"
#include "ViewAngle.hpp"
#include "Entity.hpp"

class CLocalPlayer :CEntity
{
	//private:
	//	//static CLocalPlayer* localPlayer;
	//	__int64 localPlayerBaseAdd;
	//	int* health;
	//	Vector3* position;
	//	ViewAngle* cameraViewAngle;
	//
	//private:
	//	CLocalPlayer();
	//
	public:
	//	static CLocalPlayer& GetInstance();
	//	CLocalPlayer(CLocalPlayer&) = delete;
	//	void operator=(const CLocalPlayer&) = delete;
	//
	//	__int64 GetLocalPlayerBaseAdd();
	//	int GetHealth();
		ViewAngle& GetViewAngle();
		void SetViewAngle(ViewAngle& viewAngle);
	//	Vector3* GetPosition();
	//
	//	void SetHealth(int health);
	//	void SetPosition(Vector3* pos);
	//	void PrintPlayerInfo();
		//void LoadPlayerInfo(HANDLE gameHandle, DWORD gameBase);
};

