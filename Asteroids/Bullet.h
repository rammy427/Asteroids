#pragma once

#include "Ship.h"

class Bullet
{
public:
	Bullet(const Ship& ship);
	void update(float dt);
	void draw(sf::RenderWindow& rw);
	const sf::FloatRect getRect() const;
private:
	static constexpr int width = 5;
	static constexpr int height = 8;
	static constexpr float speed = 500.0f;
	sf::RectangleShape rect;
	sf::Vector2f direction;
};