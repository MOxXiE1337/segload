#pragma once

#include "../loader.h"

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
