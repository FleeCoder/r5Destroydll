#include "MemoryHandler.hpp"
#include <iostream>
#include <iomanip>

//MemoryHandler& MemoryHandler::GetInstance()
//{
//	static MemoryHandler patternScanner;
//	return patternScanner;
//}

std::vector<uint8_t> MemoryHandler::PatternToBytes(const char* pattern)
{
	std::vector<uint8_t> bytes;
	auto start = const_cast<char*>(pattern);
	auto end = const_cast<char*>(pattern) + strlen(pattern);

	for (auto current = start; current < end; ++current) {
		if (*current == '?') {
			++current;
			bytes.push_back('?');
		}
		else {
			bytes.push_back((uint8_t)strtoul(current, &current, 16));
		}
	}
	return bytes;
}

DWORD64 MemoryHandler::PatternScan(void* hmodule, const char* pattern, int offset, int extra)
{
	auto dosHeader = (PIMAGE_DOS_HEADER)hmodule;
	auto ntHeaders = (PIMAGE_NT_HEADERS)((uint8_t*)hmodule + dosHeader->e_lfanew);

	auto sizeOfImage = ntHeaders->OptionalHeader.SizeOfImage;

	std::vector<uint8_t> patternBytes = std::move(MemoryHandler::PatternToBytes(pattern));
	uint8_t* scanBytes = reinterpret_cast<uint8_t*>(hmodule);
	auto s = patternBytes.size();
	auto d = patternBytes.data();

	for (auto i = 0ul; i < sizeOfImage - s; ++i) {
		bool found = true;
		for (auto j = 0ul; j < s; ++j) {
			if (scanBytes[i + j] != d[j] && d[j] != '?') {
				found = false;
				break;
			}
		}
		if (found) {
			if (extra)
			{			
				DWORD* varptr32 = (DWORD*)(&scanBytes[i] + offset);
				if (varptr32)
				{
					DWORD64* varptr64 = (DWORD64*)(&scanBytes[i] + *varptr32 + offset + 4);
					if (varptr64)
					{
						return *varptr64 + extra;
					}
					else
					{
						std::cerr << "Invalid Extra Pointer: " << varptr64 << std::endl;
					}
				}
				else
				{
					std::cerr << "Invalid pointer: " << varptr32 << std::endl;
				}
			}
			else
			{
				DWORD* varptr = (DWORD*)(&scanBytes[i] + offset);
				if (varptr)
					return (DWORD64)&scanBytes[i] + *varptr + offset + 4 - (DWORD64)hmodule;
			}
		}
	}
	return NULL;
}