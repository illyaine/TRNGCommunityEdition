#include "renderer_api.h"

namespace trngce::render
{
	Backend GetActiveBackend() noexcept
	{
		return Backend::LegacyDirect3D;
	}

	bool IsBackendAvailable(Backend backend) noexcept
	{
		return backend == Backend::LegacyDirect3D;
	}

	bool SelectBackend(Backend backend) noexcept
	{
		// A backend is not selectable until it has an integrated renderer.
		// In particular, DX12 must not accidentally replace the legacy path.
		return IsBackendAvailable(backend);
	}
}
