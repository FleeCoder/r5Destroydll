#pragma once
#include <Windows.h>
#include <vector>

namespace MemoryHandler
{
    std::vector<uint8_t> PatternToBytes(const char* pattern);

	template<class T>
	T Read(DWORD64 dwPtr)
	{
		if (!IsBadReadPtr((void*)dwPtr, sizeof(T)))
			return *reinterpret_cast<T*>(dwPtr);
		return NULL;
	}

	template<class T>
	bool Write(DWORD64 dwPtr, const T& value)
	{
		if (!IsBadReadPtr((void*)dwPtr, sizeof(T)))
		{
			memcpy((void*)dwPtr, value, sizeof(T));
			return true;
		}
		return false;
	}
	template<typename Return, typename ... Args>
	constexpr Return Call(void* _this, const uint32_t index, Args ... args) noexcept;


    DWORD64 PatternScan(void* hmodule, const char* pattern, int offset, int extra = 0);
}