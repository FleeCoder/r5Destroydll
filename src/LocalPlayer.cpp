#include "HackMod_Offsets_Cfg.hpp"
#include <iostream>
#include "LocalPlayer.hpp"
#include "HookHandler.hpp"

//CLocalPlayer* CLocalPlayer::localPlayer = nullptr;

CLocalPlayer::CLocalPlayer()
{
	HookHandler& hookHandler = HookHandler::GetInstance();
	//localPlayerBaseAdd = *(__int64*)(hookHandler.GetExeBaseAddress() + dwLocalPlayerBaseOffset);
	health = (int*)(localPlayerBaseAdd + dwHealthOffset);
	position = (Vector3*)(localPlayerBaseAdd + dwPlayerPositionOffset);
	cameraViewAngle = (ViewAngle*)(localPlayerBaseAdd + dwLocalPlayerAngleRotOffset);
}

__int64 CLocalPlayer::GetLocalPlayerBaseAdd()
{
	return localPlayerBaseAdd;
}

CLocalPlayer& CLocalPlayer::GetInstance()
{
	static CLocalPlayer localPlayer;
	return localPlayer;
}

int CLocalPlayer::GetHealth()
{
	return *health;
}

Vector3* CLocalPlayer::GetPosition()
{
	return position;
}

ViewAngle* CLocalPlayer::GetCameraViewAngle()
{
	return cameraViewAngle;
}

void CLocalPlayer::SetHealth(int health)
{
	*(this->health) = health;
}

void CLocalPlayer::SetPosition(Vector3* pos)
{
	this->position = pos;
}

void CLocalPlayer::PrintPlayerInfo()
{
	std::cout << "Player Health: " << *health << std::endl;
	std::cout << "Player x coordinate: " << position->x << std::endl;
	std::cout << "Player y coordinate: " << position->y << std::endl;
	std::cout << "Player z coordinate: " << position->z << std::endl;
}

//void CLocalPlayer::LoadPlayerInfo(HANDLE gameHandle, DWORD gameBase)
//{
//	ReadProcessMemory(gameHandle, (PBYTE*)(gameBase + dwLocalPlayerBaseOffset), &localPlayerBaseAdd, sizeof(DWORD), 0);
//	ReadProcessMemory(gameHandle, (PBYTE*)(localPlayerBaseAdd + dwHealthOffset), &health, sizeof(int), 0);
//	ReadProcessMemory(gameHandle, (PBYTE*)(localPlayerBaseAdd + dwPlayerPositionOffset), &position, sizeof(float[3]), 0);
//	//HookHandler::DeleteInstance();
//}