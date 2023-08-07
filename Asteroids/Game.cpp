#include "Game.h"
#include "RamWindow.h"
#include "TextureManager.h"
#include <algorithm>

Game::Game(sf::RenderWindow& rw)
	:
	rw(rw),
	ship(RamWindow::getCenter())
{
	for (int n = 0; n < 10; n++)
		asteroids.emplace_back();
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

	ship.update(dt);

	for (Bullet& b : bullets)
		b.update(dt);
	eraseLostBullets();

	for (Asteroid& a : asteroids)
		a.update(dt);
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