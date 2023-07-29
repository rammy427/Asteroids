#pragma once

#include <chrono>

class FrameTimer
{
public:
	FrameTimer();
	float mark();
private:
	std::chrono::steady_clock::time_point last;
};