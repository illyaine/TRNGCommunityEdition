#include "../TRNGCE/trngce/core_hooks.h"
#include <cassert>

namespace
{
	int levelReadyCount = 0;

	void CountLevelReady() noexcept
	{
		++levelReadyCount;
	}

	void OtherCallback() noexcept
	{
		levelReadyCount += 100;
	}
}

int main()
{
	trngce::hooks::NotifyLevelSetupComplete();
	assert(levelReadyCount == 0);
	assert(!trngce::hooks::RegisterLevelSetupCallback(nullptr));
	assert(trngce::hooks::RegisterLevelSetupCallback(&CountLevelReady));
	assert(!trngce::hooks::RegisterLevelSetupCallback(&CountLevelReady));
	assert(!trngce::hooks::RegisterLevelSetupCallback(&OtherCallback));
	trngce::hooks::NotifyLevelSetupComplete();
	trngce::hooks::NotifyLevelSetupComplete();
	assert(levelReadyCount == 2);
}
