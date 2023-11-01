// Main window.

#include "Window.h"
#include <sstream>

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

			//// Test keyboard.
			//if (wnd.kbd.KeyIsPressed(VK_MENU))
			//{
			//	MessageBox(nullptr, "ALT Key Pressed.", "Key Test", MB_OK);
			//}

			//// Test mouse capture.
			//while (!wnd.mouse.IsEmpty())
			//{
			//	const auto e = wnd.mouse.Read();
			//	switch (e.GetType())
			//	{
			//	case Mouse::Event::Type::Leave:
			//		wnd.SetTitle("Gone!");
			//		break;
			//	case Mouse::Event::Type::Move:
			//	{
			//		std::ostringstream oss;
			//		oss << "Mouse moved to (" << e.GetPosX() << "," << e.GetPosY() << ")";
			//		wnd.SetTitle(oss.str());
			//	}
			//	break;
			//	}
			//}

			// Test wheel delta
			static int i = 0;
			while (!wnd.mouse.IsEmpty())
			{
				const auto e = wnd.mouse.Read();
				switch (e.GetType())
				{
				case Mouse::Event::Type::WheelUp:
					i++;
					{
						std::ostringstream oss;
						oss << "Up: " << i;
						wnd.SetTitle(oss.str());
					}
					break;
				case Mouse::Event::Type::WheelDown:
					i--;
					{
						std::ostringstream oss;
						oss << "Down: " << i;
						wnd.SetTitle(oss.str());
					}
					break;
				}
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