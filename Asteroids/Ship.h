#pragma once

#include <SFML/Graphics.hpp>

class Ship
{
public:
	Ship(const sf::Vector2f& pos);
	void update(float dt);
	void draw(sf::RenderWindow& rw);
private:
	static constexpr int width = 32;
	static constexpr int height = 32;
	static constexpr float maxSpeed = 250.0f;
	static constexpr float acceleration = 200.0f;
	static constexpr float deceleration = 50.0f;
	static constexpr float angularSpeed = 270.0f;
	float speed = 0.0f;
	sf::Vector2f pos;
	sf::ConvexShape shape;
};