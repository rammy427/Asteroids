#include "Game.h"
#include "RamWindow.h"
#include "TextureManager.h"
#include <algorithm>

Game::Game(sf::RenderWindow& rw)
	:
	rw(rw),
	ship(RamWindow::getCenter())
{
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
			if (ev.key.code == sf::Keyboard::Space)
				bullets.emplace_back(ship);
}

void Game::updateModel()
{
	const float dt = ft.mark();
	TextureManager::clean();

	// Spawn asteroid every 2 seconds.
	elapsedTime += dt;
	if (elapsedTime >= asteroidSpawnTime)
	{
		asteroids.emplace_back();
		elapsedTime = 0.0f;
	}

	ship.update(dt);

	for (Bullet& b : bullets)
		b.update(dt);

	for (Asteroid& a : asteroids)
		a.update(dt);

	eraseLostBullets();
	doBulletAsteroidColl();
}

void Game::composeFrame()
{
	for (Bullet& b : bullets)
		b.draw(rw);

	for (Asteroid& a : asteroids)
		a.draw(rw);

	ship.draw(rw);
}

void Game::eraseLostBullets()
{
	const auto pred = [](Bullet& b) { return !b.getRect().intersects(RamWindow::getRect()); };
	const auto newEnd = std::remove_if(bullets.begin(), bullets.end(), pred);
	bullets.erase(newEnd, bullets.end());
}

void Game::doBulletAsteroidColl()
{
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
			// Set asteroid iterator to next element after deletion.
			i = asteroids.erase(i);
		else
			// Check next asteroid normally.
			i++;
	}
}