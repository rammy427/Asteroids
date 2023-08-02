#pragma once

#include <SFML/Graphics.hpp>

class Ship
{
public:
	Ship(const sf::Vector2f& pos);
	void update(float dt);
	void draw(sf::RenderWindow& rw);
	float getRotation() const;
	const sf::Vector2f getPosition() const;
	const sf::Vector2f getDirection() const;
private:
	void rotate(float dt);
	void accelerate(float dt);
	void moveForward(float dt);
	void wrapAroundScreen();
private:
	static constexpr int width = 32;
	static constexpr int height = 32;
	static constexpr int outlineThickness = 1;
	static constexpr float maxSpeed = 250.0f;
	static constexpr float acceleration = 200.0f;
	static constexpr float deceleration = 50.0f;
	static constexpr float angularSpeed = 270.0f;
	const sf::Color fillColor = sf::Color::Black;
	const sf::Color outlineColor = sf::Color::White;
	float speed = 0.0f;
	sf::ConvexShape shape;
};