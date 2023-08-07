#pragma once

#include <SFML/System.hpp>

struct RamMath
{
public:
	static float degToRad(float deg)
	{
		return deg * pi / 180;
	}
	static float getLengthSq(const sf::Vector2f& v)
	{
		return v.x * v.x + v.y * v.y;
	}
	static float getLength(const sf::Vector2f& v)
	{
		return std::sqrt(getLengthSq(v));
	}
	static sf::Vector2f getNormalized(const sf::Vector2f& v)
	{
		return v / getLength(v);
	}
public:
	static constexpr float pi = 3.141593f;
};