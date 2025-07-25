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
	//inputOffset = MemoryHandler::PatternScan(hookHandler.GetHModule(), inputOffsetSig, 3);
	engineClientOffset = MemoryHandler::PatternScan(hookHandler.GetHModule(), engineClientOffsetSig, 39);
	gameMovementOffset = MemoryHandler::PatternScan(hookHandler.GetHModule(), gameMovementOffsetSig, 3);
	//std::cout << "input offset: " << inputOffset << std::endl;
	//std::cout << "Engine Client offset: " << engineClientOffset << std::endl;
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

DWORD64 OffsetHandler::GetInputOffset()
{
	return inputOffset;
}

DWORD64 OffsetHandler::GetEngineClientOffset()
{
	return engineClientOffset;
}

DWORD64 OffsetHandler::GetGameMovementOffset()
{
	return gameMovementOffset;
}

//uintptr_t OffsetHandler::GetOffset(const char* tableName, const char* netVarName)
//{
//	return offsets[std::string(tableName) + "::" + netVarName];
//}