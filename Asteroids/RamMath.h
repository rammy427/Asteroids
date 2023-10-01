#pragma once

#define _USE_MATH_DEFINES
#include <math.h>
#include <SFML/Graphics.hpp>

namespace RamMath
{
	static float degToRad(float deg)
	{
		return deg * float(M_PI) / 180;
	}
	static float getLengthSq(const sf::Vector2f& v)
	{
		return v.x * v.x + v.y * v.y;
	}
	static float getLength(const sf::Vector2f& v)
	{
		return sqrt(getLengthSq(v));
	}
	static sf::Vector2f getNormalized(const sf::Vector2f& v)
	{
		return v / getLength(v);
	}
	static sf::FloatRect getExpanded(const sf::FloatRect& src, float padding)
	{
		const sf::Vector2f topLeft(src.left + padding, src.top + padding);
		const sf::Vector2f size = src.getSize() - sf::Vector2f(padding, padding);
		return sf::FloatRect(topLeft, size);
	}
}