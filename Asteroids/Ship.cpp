#include "RamMath.h"
#include "RamWindow.h"
#include "Ship.h"

Ship::Ship(const sf::Vector2f& pos)
{
	// Set ship vertices.
	shape.setPointCount(4);
	shape.setPoint(0, { 0, height });
	shape.setPoint(1, { width / 2,0 });
	shape.setPoint(2, { width, height });
	shape.setPoint(3, { width / 2,height * 3 / 4 });

	// Set position.
	const sf::Vector2f center = sf::Vector2f(width, height) / 2.0f;
	shape.setOrigin(center);
	shape.setPosition(pos);

	// Set outline and color.
	shape.setFillColor(fillColor);
	shape.setOutlineColor(outlineColor);
	shape.setOutlineThickness(-outlineThickness);
}

void Ship::update(float dt)
{
	rotate(dt);
	accelerate(dt);
	moveForward(dt);
	wrapAroundScreen();
}

void Ship::draw(sf::RenderWindow& rw)
{
	rw.draw(shape);
}

float Ship::getRotation() const
{
	return shape.getRotation();
}

const sf::Vector2f Ship::getPosition() const
{
	return shape.getPosition();
}

const sf::Vector2f Ship::getDirection() const
{
	const float angle = RamMath::degToRad(getRotation() - 90);
	return sf::Vector2f(std::cos(angle), std::sin(angle));
}

const sf::FloatRect Ship::getRect() const
{
	return shape.getGlobalBounds();
}

void Ship::rotate(float dt)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		shape.rotate(-angularSpeed * dt);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		shape.rotate(angularSpeed * dt);
}

void Ship::accelerate(float dt)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
		speed = std::min(speed + acceleration * dt, maxSpeed);
	else
		speed = std::max(0.0f, speed - deceleration * dt);
}

void Ship::moveForward(float dt)
{
	shape.move(getDirection() * speed * dt);
}

void Ship::wrapAroundScreen()
{
	sf::Vector2f pos = shape.getPosition();
	
	if (pos.x < -width / 2)
		pos.x = RamWindow::screenWidth + width / 2 - 1;
	else if (pos.x >= RamWindow::screenWidth + width / 2)
		pos.x = -width / 2;

	if (pos.y < -height / 2)
		pos.y = RamWindow::screenHeight + height / 2 - 1;
	else if (pos.y >= RamWindow::screenHeight + height / 2)
		pos.y = -height / 2;

	shape.setPosition(pos);
}