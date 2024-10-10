#pragma once

#include "loader_opponent.h"

#ifdef _WIN64
#pragma comment(lib, "libMinHook-x64-v141-mt.lib")
#else
#pragma comment(lib, "libMinHook-x86-v141-mt.lib")
#endif

namespace segload
{
	struct HookRecord // hook记录
	{
		uintptr_t target;
		uintptr_t detour;
		uintptr_t origin;
	};

	// 钩子管理
	class HookManager : public LoaderOpponent
	{
	private:

	public:
		HookManager(Loader* loader);

		// TODO:
		// 用minhook
		// 记录直接new就行了
		// Hook一个地址，记录 CreateHook(name, target, detour) 
		// 删除一个Hook 删除记录 RemoveHook(name)
		// 获取一个地址的原始函数 用模板 GetOriginalFunction<type>(name)	
		// 获取所有Hook 类似于PatchMangaer的 GetHooks
	};
}