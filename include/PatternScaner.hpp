#pragma once
#include <vector>

class PatternScaner
{
private:
	PatternScaner();
	std::vector<uint8_t> PatternToBytes(const char* pattern);

public:
	static PatternScaner& GetInstance();
	uint8_t* PatternScan(void* hmodule, const char* pattern);
};