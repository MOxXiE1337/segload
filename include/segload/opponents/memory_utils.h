#pragma once

#include "loader_opponent.h"

namespace segload
{
	// �ڴ������
	class MemoryUtils : public LoaderOpponent
	{
	private:

	public:
		MemoryUtils(Loader* loader);

		// TODO:
		// ��ȡģ���ַ GetModuleBase
		// ��ȡģ���С GetModuleSize
		// ��ȡģ����Ϣ GetModuleInfo 
		// ���������� (ida����) ScanSignature(module_name, signature) ScanSignature(start, end, signature) 
		
	};
}
