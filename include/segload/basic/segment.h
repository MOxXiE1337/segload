#pragma once

#include "../vendor.h"

namespace segload
{
	struct Segment
	{
		uintptr_t   address;
		size_t      virtual_size;
		size_t      raw_size;
		const void* native_data;
	};
}
