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

	// Generate random position.
	std::mt19937 rng(std::random_device{}());
	std::uniform_real_distribution<float> xDist(0, RamWindow::screenWidth);
	std::uniform_real_distribution<float> yDist(0, RamWindow::screenHeight);
	sprite.setPosition(sf::Vector2f(xDist(rng), yDist(rng)));
	
	// Generate random direction.
	std::uniform_real_distribution<float> dirDist(-1.0f, 1.0f);
	direction = RamMath::getNormalized({ dirDist(rng), dirDist(rng) });
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