#pragma once

#include "loader_opponent.h"

namespace segload
{
	struct PatchRecord // patch��¼
	{
		uintptr_t      address;
		size_t         size;
		const uint8_t* data;
	};

	// ��������
	class PatchManager : public LoaderOpponent
	{
	private:

	public:
		PatchManager(Loader* loader);

		// TODO:
		// �ǵ���VirtualProtect������
		// patchһ����ַ ApplyPatch(address, bytes) bytesʹ��ida������ ����Ϊ�ֽ�����Ȼ��patch ���� ApplyPatch(0x123, "FF D0")
		// ����Ϊ�ֽ������������segload���洴һ��utils.h Ȼ����src�ﴴһ��utils.cc
		// �ָ�һ����ַ��patch RestorePatch(address) ��unordered_map��¼ԭʼ�ֽ� ��Ҫʱ�ָ�patch
		// ��ȡ����patch GetPatches(std::vector<PatchRecord>& patches) (���õ������� �����õ� ��unordered_map�����record����vector��)	
	};
}
