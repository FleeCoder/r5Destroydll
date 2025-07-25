#pragma once
#include "ViewAngle.hpp"
#include "MemoryHandler.hpp"

class CEngineClient
{
public:
	ViewAngle& GetViewAngle();
	void SetViewAngle(ViewAngle& viewAngle);
	int Unknown0001();
	int Unknown0002();
	int Unknown0003();
	int Unknown0004();
	void* GetVtableFunctionAddress(int index);
};
