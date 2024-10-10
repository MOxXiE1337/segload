#pragma once

#include "../vendor.h"

namespace segload
{
	struct RuntimeExportSymbol
	{
		size_t      ordinal;
		uintptr_t   address;
		const char* name;
	};

	struct RuntimeModule
	{
		const char* name;
		uintptr_t   imagebase;
		size_t      imagesize;
		std::vector<RuntimeExportSymbol> export_symbols;
	};
}
