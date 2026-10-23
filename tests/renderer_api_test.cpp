#include "../TRNGCE/trngce/renderer_api.h"
#include <cassert>

int main()
{
	using trngce::render::Backend;
	assert(trngce::render::GetActiveBackend() == Backend::LegacyDirect3D);
	assert(trngce::render::IsBackendAvailable(Backend::LegacyDirect3D));
	assert(!trngce::render::IsBackendAvailable(Backend::DirectX12));
	assert(trngce::render::SelectBackend(Backend::LegacyDirect3D));
	assert(!trngce::render::SelectBackend(Backend::DirectX12));
	assert(!trngce::render::SelectBackend(static_cast<Backend>(255)));
	assert(trngce::render::GetActiveBackend() == Backend::LegacyDirect3D);
}
