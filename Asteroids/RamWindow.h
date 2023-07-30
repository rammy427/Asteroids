#pragma once

#include <SFML/System.hpp>

struct RamWindow
{
public:
	static sf::Vector2f getCenter()
	{
		return sf::Vector2f(screenWidth, screenHeight) / 2.0f;
	}
public:
	static constexpr int screenWidth = 800;
	static constexpr int screenHeight = 600;
};