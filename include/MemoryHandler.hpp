#pragma once
#include <Windows.h>
#include <vector>
#include <iostream>

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
	constexpr Return Call(void* _this, const uint32_t index, Args ... args) noexcept
	{
		using Fn = Return(__thiscall*)(void*, decltype(args)...);
		std::cout << "Function address: " << (*static_cast<void***>(_this))[index] << std::endl;
		return (*static_cast<Fn**>(_this))[index](_this, args ...);
	}

	constexpr void* GetVTableFun(void* _this, uint32_t index) noexcept
	{
		return (*static_cast<void***>(_this))[index];
	}


    DWORD64 PatternScan(void* hmodule, const char* pattern, int offset, int extra = 0);
}