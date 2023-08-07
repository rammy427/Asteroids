#pragma once

#include <SFML/Graphics.hpp>

class Asteroid
{
public:
	Asteroid();
	void update(float dt);
	void draw(sf::RenderWindow& rw);
private:
	void wrapAroundScreen();
private:
	static constexpr float speed = 30.0f;
	sf::Vector2f direction;
	sf::Texture t;
	sf::Sprite sprite;
};