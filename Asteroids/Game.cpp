#include "Game.h"
#include "RamWindow.h"
#include "TextureManager.h"
#include <algorithm>
#include <iostream>
#include <string>

Game::Game(sf::RenderWindow& rw)
	:
	rw(rw),
	ship(RamWindow::getCenter())
{
	// Set up font and text.
	font.loadFromFile("Fonts/consola.ttf");

	const sf::FloatRect rect = text.getLocalBounds();
	text.setOrigin(rect.getSize() / 2.0f);
	text.setPosition(RamWindow::getCenter());
}

void Game::run()
{
	processEvents();
	updateModel();
	rw.clear();
	composeFrame();
	rw.display();
}

void Game::processEvents()
{
	sf::Event ev;
	while (rw.pollEvent(ev))
		if (ev.type == sf::Event::Closed)
			rw.close();
		else if (ev.type == sf::Event::KeyPressed)
			if (!gameIsOver && ev.key.code == sf::Keyboard::Space)
				bullets.emplace_back(ship);
}

void Game::updateModel()
{
	const float dt = ft.mark();
	TextureManager::clean();

	if (!gameIsOver)
	{
		// Spawn asteroid every 2 seconds.
		elapsedTime += dt;
		if (elapsedTime >= asteroidSpawnTime)
		{
			asteroids.emplace_back();
			elapsedTime = 0.0f;
		}

		ship.update(dt);

		eraseLostBullets();
		doBulletAsteroidColl();
		doPlayerAsteroidColl();
	}

	for (Bullet& b : bullets)
		b.update(dt);

	for (Asteroid& a : asteroids)
		a.update(dt);
}

void Game::composeFrame()
{
	for (Bullet& b : bullets)
		b.draw(rw);

	for (Asteroid& a : asteroids)
		a.draw(rw);

	if (!gameIsOver)
		ship.draw(rw);
	else
		rw.draw(text);
}

void Game::eraseLostBullets()
{
	const auto pred = [](Bullet& b) { return !b.getRect().intersects(RamWindow::getRect()); };
	const auto newEnd = std::remove_if(bullets.begin(), bullets.end(), pred);
	bullets.erase(newEnd, bullets.end());
}

void Game::doBulletAsteroidColl()
{
	std::vector<Asteroid> children;
	for (auto i = asteroids.begin(); i != asteroids.end();)
	{
 		bool collisionHappened = false;
		for (auto j = bullets.begin(); j != bullets.end();)
		{
			if (i->getRect().intersects(j->getRect()))
			{
				// Set bullet iterator to next element after deletion.
				j = bullets.erase(j);
				collisionHappened = true;
			}
			else
				// Check next bullet normally.
				j++;
		}
		if (collisionHappened)
		{
			// Get information of the shot asteroid.
			const sf::Vector2f newPos = i->getPos();
			const int newLevel = i->getLevel() - 1;

			// Add 4 new asteroids with decreased level.
			if (newLevel >= 0)
				for (int n = 0; n < 4; n++)
					children.emplace_back(false, newPos, newLevel);

			// Delete shot asteroid and set asteroid iterator to next element after deletion.
			i = asteroids.erase(i);
		}
		else
			// Check next asteroid normally.
			i++;
	}

	if (!children.empty())
		std::move(children.begin(), children.end(), std::back_inserter(asteroids));
}

void Game::doPlayerAsteroidColl()
{
	const auto pred = [&](const Asteroid& a) {return a.getRect().intersects(ship.getRect()); };
	if (std::any_of(asteroids.begin(), asteroids.end(), pred))
		gameIsOver = true;
}