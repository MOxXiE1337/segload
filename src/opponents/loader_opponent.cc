#include "segload/opponents/loader_opponent.h"

namespace segload
{
	LoaderOpponent::LoaderOpponent(Loader* loader) : loader_(loader)
	{
	}

	Loader& LoaderOpponent::GetLoader()
	{
		return *loader_;
	}
}