#include "EngineClient.hpp"

ViewAngle& CEngineClient::GetViewAngle()
{
	ViewAngle viewAngle;
	if (!this)
		return viewAngle;

	MemoryHandler::Call<void, ViewAngle>(this, 58, viewAngle);
	return viewAngle;
}

void CEngineClient::SetViewAngle(ViewAngle& viewAngle)
{
	if (!this)
		return;
	return MemoryHandler::Call<void, ViewAngle>(this, 59, viewAngle);
}

int CEngineClient::Unknown0001()
{
	if (!this)
		return 0;
	return MemoryHandler::Call<int>(this, 44);
}

int CEngineClient::Unknown0002()
{
	if (!this)
		return 0;
	return MemoryHandler::Call<int>(this, 46);
}

int CEngineClient::Unknown0003()
{
	if (!this)
		return 0;
	return MemoryHandler::Call<int>(this, 47);
}

int CEngineClient::Unknown0004()
{
	if (!this)
		return 0;
	return MemoryHandler::Call<int>(this, 51);
}

void* CEngineClient::GetVtableFunctionAddress(int index)
{
	return MemoryHandler::GetVTableFun(this, index);
}