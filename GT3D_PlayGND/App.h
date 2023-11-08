// App.h

#pragma once
#include "Window.h"
#include "GTTimer.h"

class App
{
public:
	App();
	// Master frame / message Loop.
	int Go();

private:
	void DoFrame();

private:
	Window wnd;
	GTTimer timer;
};
