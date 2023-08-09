#pragma once

#include <SFML/Graphics.hpp>

class Asteroid
{
public:
	Asteroid();
	void update(float dt);
	void draw(sf::RenderWindow& rw);
	const sf::FloatRect getRect() const;
private:
	void wrapAroundScreen();
private:
	float speed;
	sf::Vector2f direction;
	std::shared_ptr<sf::Texture> pTex;
	sf::Sprite sprite;
};