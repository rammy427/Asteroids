#include "Bullet.h"

Bullet::Bullet(const Ship& ship)
{
	rect = sf::RectangleShape(sf::Vector2f(width, height));
	const sf::Vector2f center = sf::Vector2f(width, height) / 2.0f;

	rect.setOrigin(center);
	rect.setPosition(ship.getPosition());
	rect.setRotation(ship.getRotation());
	direction = ship.getDirection();
}

void Bullet::update(float dt)
{
	rect.move(direction * speed * dt);
}

void Bullet::draw(sf::RenderWindow& rw)
{
	rw.draw(rect);
}

const sf::FloatRect Bullet::getRect() const
{
	return rect.getGlobalBounds();
}