#pragma once
#include <map>
#include <string>
#include <Windows.h>

class OffsetHandler
{
private:
	//std::map<std::string, uintptr_t> offsets;
	DWORD64 createInterfaceOffset;
	DWORD64 netVarOffset;
	DWORD64 numEntitiesOffset;

private:
	OffsetHandler();

public:
	static OffsetHandler& GetInstance();
	DWORD64 GetInterfaceOffset();
	DWORD64 GetNetVarOffset();
	DWORD64 GetNumEntitiesAddress();

	//uintptr_t GetOffset(const char* tableName, const char* netVarName);
};