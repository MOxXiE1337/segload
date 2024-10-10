#pragma once

#include <vector>
#include <unordered_map>

namespace segload
{
	class Loader;

	class LoaderOpponent
	{
	private:
		Loader* loader_;
	public:
		LoaderOpponent(Loader* loader);
		Loader& GetLoader();
	};
}
