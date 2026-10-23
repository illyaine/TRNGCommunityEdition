#pragma once

namespace trngce::render
{
	enum class Backend : unsigned char
	{
		LegacyDirect3D,
		DirectX12
	};

	// C++ internal interface; not a TRNG plugin or binary compatibility contract.
	// Resource, texture and device contracts require a separate rendering audit.
	class IFrameRenderer
	{
	public:
		virtual ~IFrameRenderer() = default;
		virtual Backend GetBackend() const noexcept = 0;
		virtual bool BeginFrame() noexcept = 0;
		virtual bool EndFrame() noexcept = 0;
	};

	Backend GetActiveBackend() noexcept;
	bool IsBackendAvailable(Backend backend) noexcept;
	// Reject unavailable backends without changing the active renderer.
	bool SelectBackend(Backend backend) noexcept;
}
