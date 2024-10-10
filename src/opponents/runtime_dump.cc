#include "segload/opponents/runtime_dump.h"

namespace segload
{
	RuntimeDump::RuntimeDump(Loader* loader) : LoaderOpponent(loader),
		base_address_(~0),
		segments_total_size_(0)
	{
	}

	void RuntimeDump::AddRuntimeModule(const RuntimeModule& module)
	{
		runtime_modules_.push_back(module);
	}

	void RuntimeDump::AddSegment(const Segment& segment)
	{
		segments_.push_back(segment);
		segments_total_size_ += segment.virtual_size;
	}

	const std::vector<RuntimeModule>& RuntimeDump::GetRuntimeModules() const
	{
		return runtime_modules_;
	}

	const std::vector<Segment>& RuntimeDump::GetSegments() const
	{
		return segments_;
	}

	const RuntimeModule* RuntimeDump::GetRuntimeModule(const char* name) const
	{
		for (auto& module : runtime_modules_)
		{
			if (!strcmp(module.name, name))
				return &module;
		}
		return nullptr;
	}

	const RuntimeExportSymbol* RuntimeDump::FindExportSymbolByName(const RuntimeModule* module, const char* name) const
	{
		if (module == nullptr)
			return nullptr;

		for (auto& symbol : module->export_symbols)
		{
			if (!strcmp(symbol.name, name))
				return &symbol;
		}

		return nullptr;
	}

	const RuntimeExportSymbol* RuntimeDump::FindExportSymbolByAddress(const RuntimeModule* module, uintptr_t address) const
	{
		if (module == nullptr)
			return nullptr;

		for (auto& symbol : module->export_symbols)
		{
			if (symbol.address == address)
				return &symbol;
		}

		return nullptr;
	}

	const RuntimeExportSymbol* RuntimeDump::FindExportSymbolByName(const char* module_name, const char* name) const
	{
		const RuntimeModule* module = GetRuntimeModule(module_name);
		return FindExportSymbolByName(module, name);
	}

	const RuntimeExportSymbol* RuntimeDump::FindExportSymbolByAddress(const char* module_name, uintptr_t address) const
	{
		const RuntimeModule* module = GetRuntimeModule(module_name);
		return FindExportSymbolByAddress(module, address);
	}

	void RuntimeDump::SetBaseAddress(uintptr_t address)
	{
		base_address_ = address;
	}

	uintptr_t RuntimeDump::GetBaseAddress() const
	{
		return base_address_;
	}
	size_t RuntimeDump::GetSegmentsTotalSize() const
	{
		return segments_total_size_;
	}
}
