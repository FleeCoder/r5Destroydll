#include "OffsetHandler.hpp"
#include "NetVarManager.hpp"
#include "MemoryHandler.hpp"
#include "Memory_Cfg.hpp"
#include "HookHandler.hpp"
#include <iostream>

OffsetHandler::OffsetHandler()
{
	HookHandler& hookHandler = HookHandler::GetInstance();
	createInterfaceOffset = MemoryHandler::PatternScan(hookHandler.GetHModule(), createInterfaceOffsetSig,17);
	netVarOffset = MemoryHandler::PatternScan(hookHandler.GetHModule(), netVarOffsetSig, 3);
	numEntitiesOffset = MemoryHandler::PatternScan(hookHandler.GetHModule(), numEntitesOffsetSig, 3, 0xA10);
	std::cout << "CreateInterface Offset: " << createInterfaceOffset << std::endl;
	//NetVarManager& netVarManager = NetVarManager::GetInstance();
	//offsets["DT_Player::m_iHealth"] = netVarManager.GetNetVarOffset("DT_Player", "m_iHealth");
	//std::cout<<"health Offset stored in Offsets: "
	//offsets["DT_Player::m_aimAngle"] = netVarManager.GetNetVarOffset("DT_Player", "m_aimAngle");
}

OffsetHandler& OffsetHandler::GetInstance()
{
	static OffsetHandler offsetHandler;
	return offsetHandler;
}

DWORD64 OffsetHandler::GetInterfaceOffset()
{
	return createInterfaceOffset;
}

DWORD64 OffsetHandler::GetNetVarOffset()
{
	return netVarOffset;
}

DWORD64 OffsetHandler::GetNumEntitiesAddress()
{
	return numEntitiesOffset;
}

//uintptr_t OffsetHandler::GetOffset(const char* tableName, const char* netVarName)
//{
//	return offsets[std::string(tableName) + "::" + netVarName];
//}