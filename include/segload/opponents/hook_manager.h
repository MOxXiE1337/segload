#pragma once

#include "loader_opponent.h"

#ifdef _WIN64
#pragma comment(lib, "libMinHook-x64-v141-mt.lib")
#else
#pragma comment(lib, "libMinHook-x86-v141-mt.lib")
#endif

namespace segload
{
	struct HookRecord // hook��¼
	{
		uintptr_t target;
		uintptr_t detour;
		uintptr_t origin;
	};

	// ���ӹ���
	class HookManager : public LoaderOpponent
	{
	private:

	public:
		HookManager(Loader* loader);

		// TODO:
		// ��minhook
		// ��¼ֱ��new������
		// Hookһ����ַ����¼ CreateHook(name, target, detour) 
		// ɾ��һ��Hook ɾ����¼ RemoveHook(name)
		// ��ȡһ����ַ��ԭʼ���� ��ģ�� GetOriginalFunction<type>(name)	
		// ��ȡ����Hook ������PatchMangaer�� GetHooks
	};
}