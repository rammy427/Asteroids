#pragma once

#include <SFML/Graphics.hpp>

class Asteroid
{
public:
	Asteroid(bool randomized = true, const sf::Vector2f& inPos = {0,0}, int in_level = 2);
	void update(float dt);
	void draw(sf::RenderWindow& rw);
	const sf::FloatRect getRect() const;
	sf::Vector2f getPos() const;
	int getLevel() const;
private:
	void wrapAroundScreen();
private:
	static constexpr float scaleFactor = 0.3333333f;
	float speed;
	int level;
	sf::Vector2f direction;
	std::shared_ptr<sf::Texture> pTex;
	sf::Sprite sprite;
};