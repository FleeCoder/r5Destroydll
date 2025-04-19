#include <iostream>
#include <Windows.h>
#include "HookHandler.hpp"
#include "Entity.hpp"
#include "AimBot.hpp"
//HookHandler* HookHandler::hookHandler = nullptr;

HookHandler::HookHandler()
{
	hModule = GetModuleHandle(nullptr);
	exeBaseAddress = (uintptr_t)GetModuleHandle(nullptr);
	entityList = GetInterface<CEntityList>("VClientEntityList003");
}

HookHandler& HookHandler::GetInstance()
{
	static HookHandler hookHandler;
	return hookHandler;
}

HMODULE HookHandler::GetHModule()
{
	return hModule;
}

uintptr_t HookHandler::GetModuleBaseAddress()
{
	return exeBaseAddress;
}

CEntityList* HookHandler::GetEntityList()
{
	if (!entityList)
		return nullptr;
	return entityList;
}

template<typename T>
T* HookHandler::GetInterface(const char* interfaceName)
{
	using Fn = T * (*)(const char*, int*);
	std::cout << "1" << std::endl;
	if (!hModule)
		throw std::runtime_error("HMODULE is Null Pointer Exiting!!!");
	std::cout << "Hmodule: " << hModule << std::endl;
	const auto CreateIntance = GetProcAddress(hModule, "CreateInterface");
	std::cout << "Create Interface: " << CreateIntance << std::endl;
	/*std::cout << "2" << std::endl;
	if (!CreateIntance)
		throw std::runtime_error("CreateInterface recieved in null pointer exiting");
	std::cout << "3" << std::endl;
	return CreateIntance(interfaceName, nullptr);*/
}

//void HookHandler::DeleteInstance()
//{
//	delete hookHandler;
//	hookHandler = nullptr;
//}

//void HookHandler::HookMain()
//{
//	/*CLocalPlayer& localPlayer = CLocalPlayer::GetInstance();*/
//	while (true)
//	{
//		CEntity& entity = CEntity::GetInstance();
//		entity.LoadEnemyList();
//		//entity.PrintEntityList();
//		AimBot aimBot = AimBot::GetInstance();
//		aimBot.AimBotMain();
//		Sleep(50);
//	}
//}