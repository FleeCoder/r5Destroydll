#pragma once
#include <map>
#include <string>
#include <Windows.h>

class OffsetHandler
{
private:
	std::map<std::string, uintptr_t> offsets;
	DWORD createInterfaceOffset;

private:
	OffsetHandler();

public:
	static OffsetHandler& GetInstance();
	uintptr_t GetInterfaceOffset();
	uintptr_t GetOffset(const char* tableName, const char* netVarName);
};