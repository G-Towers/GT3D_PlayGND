// Main window.

#include "Window.h"

int CALLBACK WinMain(
	HINSTANCE _In_ hInstance,
	HINSTANCE _In_opt_ hPrevInstance,
	LPSTR     _In_ lpCmdLine,
	int       _In_ nCmdShow)
{
	try
	{
		Window wnd(800, 300, "GT3D Playground");	// Instantiatiate the window.

		MSG msg;
		BOOL gResult;
		while ((gResult = GetMessage(&msg, nullptr, 0, 0)) > 0)
		{
			// TranslateMessage will post auxilliary WM_CHAR messages from key msgs
			TranslateMessage(&msg);
			DispatchMessage(&msg);
			if (wnd.kbd.KeyIsPressed(VK_MENU))
			{
				MessageBox(nullptr, "ALT Key Pressed.", "Key Test", MB_OK);
			}
		}

		// check if GetMessage call itself borked
		if (gResult == -1)
		{
			throw GTWND_LAST_EXCEPT();
		}

		// wParam here is the value passed to PostQuitMessage
		return (int)msg.wParam;
	}
	catch (const GTException& e)
	{
		MessageBox(nullptr, e.what(), e.GetType(), MB_OK | MB_ICONEXCLAMATION);
	}
	catch (const std::exception& e)
	{
		MessageBox(nullptr, e.what(), "Standard Exception", MB_OK | MB_ICONEXCLAMATION);
	}
	catch (...)
	{
		MessageBox(nullptr, "No details available", "Unknown Exception", MB_OK | MB_ICONEXCLAMATION);
	}
	return -1;
}