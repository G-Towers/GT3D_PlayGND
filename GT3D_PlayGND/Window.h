// Window.h
// Responsible for the creation and the destruction of the window.
// Also responsible for message handling and operations that work
// with the handle to the window.

#pragma once
#include "FastWin.h"

class Window
{
private:
	// singleton manages registration/cleanup of window class
	class WindowClass
	{
	public:
		static const char* GetName() noexcept;	// Gets the name of the class.
		static HINSTANCE GetInstance() noexcept;	// Gets the instance of the class.
	private:
		WindowClass() noexcept;
		// Constructor that registers the window.
		~WindowClass();
		// Destructor that unregisters.
		WindowClass(const WindowClass&) = delete;
		WindowClass& operator=(const WindowClass&) = delete;
		static constexpr const char* wndClassName = "GT3DClass";
		static WindowClass wndClass;	// Static instance because only one window.
		HINSTANCE hInst;	// Stores the instance.
	};
public:
	Window(int width, int height, const char* name) noexcept;
	// Constructor to create the window.
	~Window();
	// Destroys the window.
	Window(const Window&) = delete;
	Window& operator=(const Window&) = delete;
private:
	static LRESULT CALLBACK HandleMsgSetup(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam) noexcept;
	// Only sets up the pointer to the instance and installs the second handler.
	static LRESULT CALLBACK HandleMsgThunk(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam) noexcept;
	// Adapts from win32 calling convention to C++ member call convention.
	LRESULT HandleMsg(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam) noexcept;
	// The Message handler.
private:
	int width;	// Dimensions of the window.
	int height;
	HWND hWnd;	// Handle to the window.
};
