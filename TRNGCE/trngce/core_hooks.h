#pragma once

namespace trngce::hooks
{
	// Internal engine callback only; not a TRNG plugin ABI.
	// Register during startup, before the first level setup.
	using LevelSetupCallback = void (*)() noexcept;

	// Only the first non-null registration succeeds in this initial stage.
	// No callback is installed by default.
	bool RegisterLevelSetupCallback(LevelSetupCallback callback) noexcept;

	// Called on the game thread after existing TRNG level setup completes.
	void NotifyLevelSetupComplete() noexcept;
}
