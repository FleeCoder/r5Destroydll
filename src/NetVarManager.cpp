#include "HookHandler.hpp"
#include "PatternScaner.hpp"
#include "NetVarManager.hpp"
#include <iostream>

NetVarManager::NetVarManager()
{
	HookHandler& hookHandler = HookHandler::GetInstance();
	HMODULE hModule = hookHandler.GetHModule();
	PatternScaner& patternScanner = PatternScaner::GetInstance();
	uint8_t* netVarPatternScanPos = patternScanner.PatternScan(hModule, netVarOffsetSig);
	client = NULL;
	if (netVarPatternScanPos)
	{
		client = *(Client**)((uintptr_t)netVarPatternScanPos + *(uint32_t*)(netVarPatternScanPos + 3) + 7);
	}
}

NetVarManager& NetVarManager::GetInstance()
{
	static NetVarManager netVarManger;
	return netVarManger;
}

intptr_t NetVarManager::GetOffset(RecvTable* table, const char* tableName, const char* netVarName)
{
	for (int i = 0;i < table->nProps;i++)
	{
		RecvProp* prop = table->pProps[i];

		if (prop)
		{
			//std::cout << "TableName: " << std::string(table->netTableName) << "\tNetVarName: " << std::string(prop->pVarName) << "\tNetVarOffset: " << prop->offset << std::endl;
			if (!_stricmp(prop->pVarName, netVarName))
				return prop->offset;
			if (prop->recvTable)
			{
				intptr_t offset = GetOffset(prop->recvTable, tableName, netVarName);
				if (offset)
				{
					return offset + prop->offset;
				}
			}
		}
	}
	return NULL;
}

intptr_t NetVarManager::GetNetVarOffset(const char* tableName, const char* netVarName)
{
	for (Client* currClient=client;currClient;currClient=currClient->next)
	{
		if (currClient->pRecvTable)
		{
			if (!_strcmpi(currClient->pRecvTable->netTableName, tableName))
				GetOffset(currClient->pRecvTable, tableName, netVarName);
		}
	}
	return NULL;
}