#pragma once

#include "loader_opponent.h"

namespace segload
{
	// 内存帮助类
	class MemoryUtils : public LoaderOpponent
	{
	private:

	public:
		MemoryUtils(Loader* loader);

		// TODO:
		// 获取模块基址 GetModuleBase
		// 获取模块大小 GetModuleSize
		// 获取模块信息 GetModuleInfo 
		// 搜索特征码 (ida类型) ScanSignature(module_name, signature) ScanSignature(start, end, signature) 
		
	};
}
