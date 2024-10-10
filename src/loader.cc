#include "segload/loader.h"

namespace segload
{
	Loader::Loader() :
		log_manager_(this),
		runtime_dump_(this),
		segment_mapper_(this)
	{
	}
}
