#include "core_hooks.h"
#include <atomic>

namespace trngce::hooks
{
	static std::atomic<LevelSetupCallback> levelSetupCallback{nullptr};

	bool RegisterLevelSetupCallback(LevelSetupCallback callback) noexcept
	{
		if (!callback)
			return false;

		LevelSetupCallback expected = nullptr;
		return levelSetupCallback.compare_exchange_strong(expected, callback);
	}

	void NotifyLevelSetupComplete() noexcept
	{
		const LevelSetupCallback callback = levelSetupCallback.load();
		if (callback)
			callback();
	}
}
