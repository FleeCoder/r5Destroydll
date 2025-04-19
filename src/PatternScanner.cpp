#include "PatternScaner.hpp"
#include <iostream>
#include <iomanip>
#include <Windows.h>

PatternScaner::PatternScaner()
{

}

PatternScaner& PatternScaner::GetInstance()
{
	static PatternScaner patternScanner;
	return patternScanner;
}

std::vector<uint8_t> PatternScaner::PatternToBytes(const char* pattern)
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

uint8_t* PatternScaner::PatternScan(void* hmodule, const char* pattern)
{
	auto dosHeader = (PIMAGE_DOS_HEADER)hmodule;
	auto ntHeaders = (PIMAGE_NT_HEADERS)((uint8_t*)hmodule + dosHeader->e_lfanew);

	auto sizeOfImage = ntHeaders->OptionalHeader.SizeOfImage;

	std::vector<uint8_t> patternBytes = std::move(PatternToBytes(pattern));
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
			return &scanBytes[i];
		}
	}
	return nullptr;
}