#pragma once

#include "loader_opponent.h"

namespace segload
{
	struct PatchRecord // patch记录
	{
		uintptr_t      address;
		size_t         size;
		const uint8_t* data;
	};

	// 补丁管理
	class PatchManager : public LoaderOpponent
	{
	private:

	public:
		PatchManager(Loader* loader);

		// TODO:
		// patch一个地址 ApplyPatch(address, bytes) bytes使用ida特征码 解析为字节数组然后patch 比如 ApplyPatch(0x123, "FF D0")
		// 恢复一个地址的patch RestorePatch(address) 用unordered_map记录原始字节 必要时恢复patch
		// 获取所有patch GetPatches(std::vector<PatchRecord>& patches) (不用担心性能 调试用的 把unordered_map里面的record丢进vector里)	
	};
}
