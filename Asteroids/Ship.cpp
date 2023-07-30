#include "RamMath.h"
#include "RamWindow.h"
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
		angle -= angularSpeed * dt;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		angle += angularSpeed * dt;
	shape.setRotation(angle);

	// Speed up or slow down ship.
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
		speed = std::min(speed + acceleration * dt, maxSpeed);
	else
		speed = std::max(0.0f, speed - deceleration * dt);

	// Calculate direction and change position.
	const float angleDiff = RamMath::degToRad(angle - 90);
	const sf::Vector2f direction = { std::cos(angleDiff), std::sin(angleDiff)};
	pos += direction * speed * dt;

	// Wrap ship around screen.
	if (pos.x < -width / 2)
		pos.x = RamWindow::screenWidth + width / 2 - 1;
	else if (pos.x >= RamWindow::screenWidth + width / 2)
		pos.x = -width / 2;

	if (pos.y < -height / 2)
		pos.y = RamWindow::screenHeight + height / 2 - 1;
	else if (pos.y >= RamWindow::screenHeight + height / 2)
		pos.y = -height / 2;

	// Set ship position accordingly.
	shape.setPosition(pos);
}

void Ship::draw(sf::RenderWindow& rw)
{
	rw.draw(shape);
}