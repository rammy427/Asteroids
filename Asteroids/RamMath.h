#pragma once

struct RamMath
{
public:
	static float degToRad(float deg)
	{
		return deg * pi / 180;
	}
public:
	static constexpr float pi = 3.141593f;
};