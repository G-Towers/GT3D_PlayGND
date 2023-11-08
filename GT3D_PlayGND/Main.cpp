// Main window.

#include "App.h"


int CALLBACK WinMain(
	HINSTANCE _In_ hInstance,
	HINSTANCE _In_opt_ hPrevInstance,
	LPSTR     _In_ lpCmdLine,
	int       _In_ nCmdShow)
{
	try
	{
		return App{}.Go();
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