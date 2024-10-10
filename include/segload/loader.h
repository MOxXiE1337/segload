#pragma once

#include "opponents/log_manager.h"
#include "opponents/runtime_dump.h"
#include "opponents/segment_mapper.h"

namespace segload
{
	enum class LoaderStage
	{
		kPrevMap,
		kPrevInvoke,
		kAfterInvoke
	};

	class Loader
	{
	private:
		LogManager    log_manager_;
		RuntimeDump   runtime_dump_;
		SegmentMapper segment_mapper_;
		
	public:
		Loader();

		virtual bool Callback(LoaderStage stage) = 0;
	public:

		// getters
		LogManager& GetLogManager() { return log_manager_; }
		RuntimeDump& GetRuntimeDump() { return runtime_dump_; }
		SegmentMapper& GetSegmentMapper() { return segment_mapper_; }

	};
}
