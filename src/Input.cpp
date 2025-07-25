#include "Input.hpp"

void* CInput::GetCreateMove()
{
	if (!this)
		return nullptr;
	return MemoryHandler::GetVTableFun(this, 4);
}