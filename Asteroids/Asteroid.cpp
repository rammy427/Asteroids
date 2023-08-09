#include "Asteroid.h"
#include "RamMath.h"
#include "RamWindow.h"
#include "TextureManager.h"
#include <random>

Asteroid::Asteroid()
{
	pTex = TextureManager::acquire("Sprites/asteroid.png");
	sprite.setTexture(*pTex);
	sprite.setOrigin(sf::Vector2f(pTex->getSize() / 2u));

	std::mt19937 rng(std::random_device{}());

	// Generate random position with bounding rectangle.
	const float padding = 10.0f;
	const sf::FloatRect boundingRect = RamMath::getExpanded(RamWindow::getRect(), padding);
	std::uniform_real_distribution<float> xDist(0, RamWindow::screenWidth);
	std::uniform_real_distribution<float> yDist(0, RamWindow::screenHeight);
	sf::Vector2f pos;
	do
	{
		pos = { xDist(rng), yDist(rng) };
	}
	while (boundingRect.contains(pos));
	sprite.setPosition(pos);
	
	// Generate random direction.
	std::uniform_real_distribution<float> dirDist(-1.0f, 1.0f);
	direction = RamMath::getNormalized({ dirDist(rng), dirDist(rng) });

	// Generate random speed.
	std::uniform_real_distribution<float> speedDist(10.0f, 100.0f);
	speed = speedDist(rng);

	// Generate random rotation.
	std::uniform_real_distribution<float> angleDist(0.0f, 360.0f);
	sprite.rotate(angleDist(rng));
}

void Asteroid::update(float dt)
{
	sprite.move(direction * speed * dt);
	wrapAroundScreen();
}

void Asteroid::draw(sf::RenderWindow& rw)
{
	rw.draw(sprite);
}

const sf::FloatRect Asteroid::getRect() const
{
	return sprite.getGlobalBounds();
}

void Asteroid::wrapAroundScreen()
{
	sf::Vector2f pos = sprite.getPosition();
	const float width = float(pTex->getSize().x);
	const float height = float(pTex->getSize().y);

	if (pos.x < -width / 2)
		pos.x = RamWindow::screenWidth + width / 2 - 1;
	else if (pos.x >= RamWindow::screenWidth + width / 2)
		pos.x = -width / 2;

	if (pos.y < -height / 2)
		pos.y = RamWindow::screenHeight + height / 2 - 1;
	else if (pos.y >= RamWindow::screenHeight + height / 2)
		pos.y = -height / 2;

	sprite.setPosition(pos);
}