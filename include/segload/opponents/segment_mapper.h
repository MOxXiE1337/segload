#pragma once

#include "loader_opponent.h"

namespace segload
{
	enum class SegmentMapperMode
	{
		kUndefined,
		kStaticMapping,
		kDynamicMapping
	};

	class SegmentMapper : public LoaderOpponent
	{
	private:
		SegmentMapperMode mapping_mode_;
		std::unordered_map<uintptr_t, uintptr_t> segment_maps_; // key: from, value: to
	public:
		SegmentMapper(Loader* loader);

		void SetMode(SegmentMapperMode mode);

		uintptr_t TranslateAddress(uintptr_t address);
		uintptr_t TranslateOffset(ptrdiff_t offset);
	};
}
