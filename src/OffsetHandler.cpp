#include "OffsetHandler.hpp"
#include "NetVarManager.hpp"
#include "PatternScaner.hpp"
#include "HookHandler.hpp"
#include <iostream>

OffsetHandler::OffsetHandler()
{
	HookHandler& hookHandler = HookHandler::GetInstance();
	PatternScaner& patternScanner = PatternScaner::GetInstance();
	uint8_t* createInterfacePatternScanPos = patternScanner.PatternScan(hookHandler.GetHModule(), createInterfaceOffsetSig) + 15;
	createInterfaceOffset = (uintptr_t)createInterfacePatternScanPos + *(DWORD*)(createInterfacePatternScanPos + 2) + 6 - hookHandler.GetModuleBaseAddress();
	std::cout << "CreateInterface Offset: " << createInterfaceOffset << std::endl;
	NetVarManager& netVarManager = NetVarManager::GetInstance();
	 offsets["DT_Player::m_iHealth"] = netVarManager.GetNetVarOffset("DT_Player", "m_iHealth");
	//offsets["DT_Player::m_aimAngle"] = netVarManager.GetNetVarOffset("DT_Player", "m_aimAngle");
}

OffsetHandler& OffsetHandler::GetInstance()
{
	static OffsetHandler offsetHandler;
	return offsetHandler;
}

uintptr_t OffsetHandler::GetInterfaceOffset()
{
	return createInterfaceOffset;
}

uintptr_t OffsetHandler::GetOffset(const char* tableName, const char* netVarName)
{
	return offsets[std::string(tableName) + "::" + netVarName];
}