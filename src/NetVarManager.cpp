#include "HookHandler.hpp"
#include "OffsetHandler.hpp"
#include "NetVarManager.hpp"
#include "MemoryHandler.hpp"
#include <iostream>

NetVarManager::NetVarManager()
{
	HookHandler& hookHandler = HookHandler::GetInstance();
	OffsetHandler& offsetHandler = OffsetHandler::GetInstance();
	client = MemoryHandler::Read<Client*>(hookHandler.GetModuleBaseAddress() + offsetHandler.GetNetVarOffset());
}

NetVarManager& NetVarManager::GetInstance()
{
	static NetVarManager netVarManger;
	return netVarManger;
}

uintptr_t NetVarManager::GetOffset(RecvTable* table, const char* netVarName)
{
	for (int i = 0;i < table->nProps;i++)
	{
		RecvProp* prop = table->pProps[i];

		if (prop)
		{
			//std::cout << "TableName: " << std::string(table->netTableName) << "\tNetVarName: " << std::string(prop->pVarName) << "\tNetVarOffset: " << prop->offset << std::endl;
			if (!_stricmp(prop->pVarName, netVarName))
			{
				return prop->offset;
			}
			if (prop->recvTable)
			{
				intptr_t offset = GetOffset(prop->recvTable, netVarName);
				if (offset)
				{
					return offset + prop->offset;
				}
			}
		}
	}
	return NULL;
}

uintptr_t NetVarManager::GetNetVarOffset(const char* tableName, const char* netVarName)
{
	for (Client* currClient=client;currClient;currClient=currClient->next)
	{		
		if (currClient->pRecvTable)
		{
			if (!_strcmpi(currClient->pRecvTable->netTableName, tableName))
			{
				return GetOffset(currClient->pRecvTable, netVarName);
			}
		}
	}
	return NULL;
}