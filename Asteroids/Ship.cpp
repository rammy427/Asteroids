#include "RamMath.h"
#include "Ship.h"

Ship::Ship(const sf::Vector2f& pos)
	:
	pos(pos)
{
	shape.setPointCount(4);

	shape.setPoint(0, { 0, height });
	shape.setPoint(1, { width / 2,0 });
	shape.setPoint(2, { width, height });
	shape.setPoint(3, { width / 2,height * 3 / 4 });

	const sf::Vector2f center = sf::Vector2f(width, height) / 2.0f;
	shape.setOrigin(center);
	shape.setPosition(pos);
}

void Ship::update(float dt)
{
	// Rotate ship.
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		shape.rotate(-angularSpeed * dt);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		shape.rotate(angularSpeed * dt);

	// Speed up or slow down ship.
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
		speed = std::min(speed + acceleration * dt, maxSpeed);
	else
		speed = std::max(0.0f, speed - deceleration * dt);

	// Calculate direction and move ship along it.
	const float angle = RamMath::degToRad(shape.getRotation() - 90);
	const sf::Vector2f direction = { std::cos(angle), std::sin(angle)};
	shape.move(direction * speed * dt);
}

void Ship::draw(sf::RenderWindow& rw)
{
	rw.draw(shape);
}