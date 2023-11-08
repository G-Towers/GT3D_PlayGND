// GTTimer.cpp

#include "GTTimer.h"

using namespace std::chrono;

GTTimer::GTTimer()
{
	last = steady_clock::now();
}

float GTTimer::Mark()
{
	const auto old = last;
	last = steady_clock::now();
	const duration<float> frametime = last - old;
	return frametime.count();
}

float GTTimer::Peek() const
{
	return duration<float>(steady_clock::now() - last).count();
}