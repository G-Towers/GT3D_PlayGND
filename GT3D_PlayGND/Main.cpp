// Main window.

#include "Window.h"

int CALLBACK WinMain(
	HINSTANCE _In_ hInstance,
	HINSTANCE _In_opt_ hPrevInstance,
	LPSTR     _In_ lpCmdLine,
	int       _In_ nCmdShow)
{
	Window wnd(800, 300, "GT3D Playground");	// Instantiatiate the window.

	MSG msg;
	BOOL gResult;
	while ((gResult = GetMessage(&msg, nullptr, 0, 0)) > 0)
	{
		// TranslateMessage will post auxilliary WM_CHAR messages from key msgs
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	// check if GetMessage call itself borked
	if (gResult == -1)
	{
		return -1;
	}

	// wParam here is the value passed to PostQuitMessage
	return (int)msg.wParam;
}