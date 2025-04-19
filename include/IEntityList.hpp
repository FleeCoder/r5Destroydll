#pragma once
#include "Entity.hpp"

class IEntityList
{
public:
	virtual void* UnknwonFun_001() = 0;
	virtual void* UnknwonFun_002() = 0;
	virtual void* UnknwonFun_003() = 0;
	virtual void* UnknwonFun_004() = 0;

	virtual CEntity* GetClientEntity(int entnum) = 0;
	virtual void* UnknwonFun_005() = 0;

	// Returns number of entities currently in use
	virtual int					NumberOfEntities(bool bIncludeNonNetworkable=false) = 0;

	// Returns highest index actually used
	virtual int					GetHighestEntityIndex(void) = 0;

	// Sizes entity list to specified size
	virtual void				SetMaxEntities(int maxents) = 0;
	virtual int					GetMaxEntities() = 0;
};
