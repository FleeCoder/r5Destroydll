#pragma once
#include <Windows.h>
#include "EntityList.hpp"
#include "OffsetHandler.hpp"

class HookHandler
{
private:
	//static HookHandler* hookHandler;
	HMODULE hModule;
	uintptr_t exeBaseAddress;
	CEntityList* entityList;


private:
	HookHandler();

public:
	HookHandler(HookHandler&) = delete;
	void operator=(const HookHandler&) = delete;

	template<typename T> 
	T* GetInterface(const char* interfaceName);

	static HookHandler& GetInstance();
	HMODULE GetHModule();
	uintptr_t GetModuleBaseAddress();
	void LoadInterfaces();
	CEntityList* GetEntityList();
	//static void DeleteInstance();
	void HookMain();
};