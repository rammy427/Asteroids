#pragma once

#include <SFML/Graphics.hpp>

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
	static sf::FloatRect getExpanded(const sf::FloatRect& src, float padding)
	{
		const sf::Vector2f topLeft(src.left + padding, src.top + padding);
		const sf::Vector2f size = src.getSize() - sf::Vector2f(padding, padding);
		return sf::FloatRect(topLeft, size);
	}
public:
	static constexpr float pi = 3.141593f;
};