#pragma once
#include <Windows.h>
#include "PatternScaner_Cfg.hpp"

typedef struct RecvProp RecvProp;
typedef struct RecvTable RecvTable;
typedef struct Client Client;

struct RecvTable
{
	void* pad0001; //0x0000
	RecvProp** pProps; //0x0008
	int nProps; //0x0010
	char pad0002[149][8]; //0x0014
	int pad0003; //0x04BC
	void* decoder; //0x04C0
	char* netTableName; //0x04C8
	bool initialized; //0x04D0
	bool inMainList; //0x04D1
}; //Size: 0x04D2

struct RecvProp
{
	int type; //0x0000
	int offset; //0x0004
	char pad_0008[24]; //0x0008
	RecvTable* recvTable; //0x0020
	char* pVarName; //0x0028
	bool insideArray; //0x0030
	char pad_0031[7]; //0x0031
	RecvProp* pArrayProp; //0x0038
	void* proxyFn; //0x0040
	char pad_0048[12]; //0x0048
	int flags; //0x0054
	int elementStride; //0x0058
	int numElements; //0x005C
}; //Size: 0x0060

struct Client
{
	void* pCreateFn; //0x0000
	void* PCreateEventFn; //0x0008
	char* networkName; //0x0010
	RecvTable* pRecvTable; //0x0018
	Client* next; //0x0020
	int id; //0x0028
}; //Size: 0x002C

class NetVarManager
{
private:
	Client* client;
	NetVarManager();
	intptr_t GetOffset(RecvTable* table, const char* tableName, const char* netVarName);

public:
	static NetVarManager& GetInstance();
	bool Initialize();
	intptr_t GetNetVarOffset(const char* tableName, const char* netVarName);
};