#include "segload/opponents/segment_mapper.h"

namespace segload
{
	SegmentMapper::SegmentMapper(Loader* loader) : LoaderOpponent(loader),
		mapping_mode_(SegmentMapperMode::kUndefined)
	{
	}

	void SegmentMapper::SetMode(SegmentMapperMode mode)
	{
		mapping_mode_ = mode;
	}

	uintptr_t SegmentMapper::TranslateAddress(uintptr_t address)
	{
		Loader& loader = GetLoader();
		RuntimeDump& dump = loader.GetRuntimeDump();

		for (auto& segment : dump.GetSegments())
		{
			if (address >= segment.address && address < segment.address + segment.virtual_size)
			{
				// not mapped?
				auto it = segment_maps_.find(segment.address);

				if (it == segment_maps_.end())
					return ~0;

				return it->second + (address - segment.address);
			}
		}

		return ~0;
	}

	uintptr_t SegmentMapper::TranslateOffset(ptrdiff_t offset)
	{
		Loader& loader = GetLoader();
		RuntimeDump& dump = loader.GetRuntimeDump();
		uintptr_t base_address = dump.GetBaseAddress();

		// base address not set?
		if (base_address == ~0)
		{
			// TODO: report error...
			return ~0;
		}

		return TranslateAddress(base_address + offset);
	}
}

