#include <iostream>
#include <Windows.h>
#include "HookHandler.hpp"
#include "OffsetHandler.hpp"
#include "Entity.hpp"
#include "AimBot.hpp"
#include "MemoryHandler.hpp"
//HookHandler* HookHandler::hookHandler = nullptr;

HookHandler::HookHandler() :input{ nullptr }, entityList{ nullptr }, engineClient{ nullptr }
{
	hModule = GetModuleHandle(nullptr);
	exeBaseAddress = (uintptr_t)GetModuleHandle(nullptr);
	//entityList = GetInterface<CEntityList>("VClientEntityList003");
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
	return entityList;
}

CEngineClient* HookHandler::GetEngineClient()
{
	return engineClient;
}

template<typename T>
T* HookHandler::GetInterface(const char* interfaceName)
{
	using Fn = T * (*)(const char*, int*);
	OffsetHandler& offsetHandler = OffsetHandler::GetInstance();
	uintptr_t getInterfaceAddress = exeBaseAddress + offsetHandler.GetInterfaceOffset();
	if (!getInterfaceAddress)
		throw std::runtime_error("CreateInterface is Null Pointer Exiting!!!");
	std::cout << "Get Interface Address: " << getInterfaceAddress << std::endl;
	const auto CreateInterface = MemoryHandler::Read<Fn>(getInterfaceAddress);
	std::cout << "Create Interface: " << CreateInterface << std::endl;
	return CreateInterface(interfaceName, nullptr);
	// std::cout << "1" << std::endl;
	// if (!hModule)
	// 	throw std::runtime_error("HMODULE is Null Pointer Exiting!!!");
	// std::cout << "Hmodule: " << hModule << std::endl;
	// const auto CreateIntance = GetProcAddress(hModule, "CreateInterface");
	// std::cout << "Create Interface: " << CreateIntance << std::endl;
	/*std::cout << "2" << std::endl;
	if (!CreateIntance)
		throw std::runtime_error("CreateInterface recieved in null pointer exiting");
	std::cout << "3" << std::endl;
	return CreateIntance(interfaceName, nullptr);*/
}

void HookHandler::LoadInterfaces()
{
	OffsetHandler& offsetHandler = OffsetHandler::GetInstance();
	entityList = GetInterface<CEntityList>("VClientEntityList003");

	//input = MemoryHandler::Read<CInput*>(exeBaseAddress + offsetHandler.GetInputOffset());
	engineClient = MemoryHandler::Read<CEngineClient*>(exeBaseAddress + offsetHandler.GetEngineClientOffset());
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