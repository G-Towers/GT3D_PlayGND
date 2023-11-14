// Graphics.cpp

#include "Graphics.h"
#pragma comment(lib, "d3d11.lib")	// Links to the library for d3d11 (will cause a linker error if not linked).


Graphics::Graphics(HWND hWnd)
{
	DXGI_SWAP_CHAIN_DESC sd = {};
	sd.BufferDesc.Width = 0;	// Buffer width and height, set to 0 means get these values from the window size.
	sd.BufferDesc.Height = 0;
	sd.BufferDesc.Format = DXGI_FORMAT_B8G8R8A8_UNORM;	// The layout of the pixels(color channels).
	sd.BufferDesc.RefreshRate.Numerator = 0;	// Refresh rate, 0 uses default for windowed mode.
	sd.BufferDesc.RefreshRate.Denominator = 0;
	sd.BufferDesc.Scaling = DXGI_MODE_SCALING_UNSPECIFIED;	// Scaling and ScanlineOrdering not specified.
	sd.BufferDesc.ScanlineOrdering = DXGI_MODE_SCANLINE_ORDER_UNSPECIFIED;
	sd.SampleDesc.Count = 1;	// Sampling mode and Quantity sets anti-aliasing.
	sd.SampleDesc.Quality = 0;	// Values of 1 and 0 sets to no anti-aliasing.
	sd.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT;	// Sets the buffer usage to the render target(pipeline will render here).
	sd.BufferCount = 1;	// Sets to 1 back buffer (1 front buffer) for double buffering.
	sd.OutputWindow = hWnd;	// Output window.
	sd.Windowed = TRUE;	// Windowed mode.
	sd.SwapEffect = DXGI_SWAP_EFFECT_DISCARD;	// Effect used for flipping/presentation (the vanilla setting).
	sd.Flags = 0;	// Additional flags.

	// Create Device and front/back buffers, swap chain and rendering contexts.
	D3D11CreateDeviceAndSwapChain(
		nullptr,	// Choose the graphics adapter. null sets to default.
		D3D_DRIVER_TYPE_HARDWARE,	// Set the driver type. Set to the main one for hardware acceleration.
		nullptr,	// Handle to a Software Driver.
		0,	// UINT Flags.
		nullptr,	// Feature levels.
		0,
		D3D11_SDK_VERSION,	// Software Development Kit Version.
		&sd,	// Pointer to the swap chain descriptor structure.
		&pSwap,	// Pointer to the Swap Chain.
		&pDevice,	// Ponter to the device.
		nullptr,	// Output pointer for feature level.
		&pContext	// Set the Context (pointer to pointer to Immediate Context).

	);
	// Gain access to texture subresource in swap chain (back buffer).
	ID3D11Resource* pBackBuffer = nullptr;
	pSwap->GetBuffer(0, __uuidof(ID3D11Resource), reinterpret_cast<void**>(&pBackBuffer));
	pDevice->CreateRenderTargetView(pBackBuffer, nullptr, &pTarget);
	pBackBuffer->Release();
}

Graphics::~Graphics()
{
	if (pTarget != nullptr)
	{
		pTarget->Release();
	}
	if (pContext != nullptr)
	{
		pContext->Release();
	}
	if (pSwap != nullptr)
	{
		pSwap->Release();
	}
	if (pDevice != nullptr)
	{
		pDevice->Release();
	}
}

void Graphics::EndFrame()
{
	pSwap->Present(1u, 0u);
}
