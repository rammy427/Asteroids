#pragma once

#include <SFML/Graphics.hpp>

struct RamWindow
{
public:
	static sf::Vector2f getCenter()
	{
		return sf::Vector2f(screenWidth, screenHeight) / 2.0f;
	}
	static sf::FloatRect getRect()
	{
		return sf::FloatRect({ 0,0 }, { screenWidth, screenHeight });
	}
public:
	static constexpr int screenWidth = 800;
	static constexpr int screenHeight = 600;
};