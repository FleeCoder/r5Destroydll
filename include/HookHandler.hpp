#pragma once
#include <Windows.h>
#include "EntityList.hpp"
#include "OffsetHandler.hpp"
#include "Input.hpp"
#include "EngineClient.hpp"

class HookHandler
{
private:
	//static HookHandler* hookHandler;
	HMODULE hModule;
	uintptr_t exeBaseAddress;
	CEntityList* entityList;
	CInput* input;
	CEngineClient* engineClient;


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
	CEngineClient* GetEngineClient();
	//static void DeleteInstance();
	void HookMain();
};