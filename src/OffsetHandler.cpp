#include "OffsetHandler.hpp"
#include "NetVarManager.hpp"
#include "PatternScaner.hpp"
#include "HookHandler.hpp"
#include <iostream>

OffsetHandler::OffsetHandler()
{
	HookHandler& hookHandler = HookHandler::GetInstance();
	PatternScaner& patternScanner = PatternScaner::GetInstance();
	uint8_t* netVarPatternScanPos = patternScanner.PatternScan(hookHandler.GetHModule(), netVarOffsetSig);
	createInterfaceOffset = (uintptr_t)netVarPatternScanPos + *(DWORD*)(netVarPatternScanPos + 25) - hookHandler.GetModuleBaseAddress();
	std::cout << "CreateInterface Offset: " << createInterfaceOffset << std::endl;
	NetVarManager& netVarManager = NetVarManager::GetInstance();
	offsets["lol::lol"] = netVarManager.GetNetVarOffset("lol", "lol");
	//offsets["DT_Player::m_aimAngle"] = netVarManager.GetNetVarOffset("DT_Player", "m_aimAngle");
}

OffsetHandler& OffsetHandler::GetInstance()
{
	static OffsetHandler offsetHandler;
	return offsetHandler;
}

uintptr_t OffsetHandler::GetOffset(const char* tableName, const char* netVarName)
{
	return offsets[std::string(tableName) + "::" + netVarName];
}