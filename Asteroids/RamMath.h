#pragma once

namespace RamMath
{
	static constexpr float pi = 3.141593f;
	float DegToRad(float deg)
	{
		return deg * pi / 180;
	}
}