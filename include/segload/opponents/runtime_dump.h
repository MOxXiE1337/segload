#pragma once

#include "loader_opponent.h"

#include "../basic/runtime_module.h"
#include "../basic/segment.h"

namespace segload
{
	class RuntimeDump : public LoaderOpponent
	{
	private:
		uintptr_t base_address_;
		size_t segments_total_size_;

		std::vector<RuntimeModule> runtime_modules_;
		std::vector<Segment> segments_;

	public:
		RuntimeDump(Loader* loader);

		void AddRuntimeModule(const RuntimeModule& module);
		void AddSegment(const Segment& segment);

		const std::vector<RuntimeModule>& GetRuntimeModules() const;

		// used by segment mapper
		const std::vector<Segment>& GetSegments() const;

		const RuntimeModule* GetRuntimeModule(const char* name) const;

		const RuntimeExportSymbol* FindExportSymbolByName(const RuntimeModule* module, const char* name) const;
		const RuntimeExportSymbol* FindExportSymbolByAddress(const RuntimeModule* module, uintptr_t address) const;
		const RuntimeExportSymbol* FindExportSymbolByName(const char* module_name, const char* name) const;
		const RuntimeExportSymbol* FindExportSymbolByAddress(const char* module_name, uintptr_t address) const;

		void      SetBaseAddress(uintptr_t address);
		uintptr_t GetBaseAddress() const;
		size_t    GetSegmentsTotalSize() const;
	};
}
