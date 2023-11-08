// GTTimer.h

#pragma once
#include <chrono>

class GTTimer
{
public:
	GTTimer();
	float Mark();
	float Peek() const;

private:
	std::chrono::steady_clock::time_point last;
};