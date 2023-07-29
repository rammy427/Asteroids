#include "Game.h"

Game::Game(sf::RenderWindow& rw)
	:
	rw(rw)
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
}

void Game::updateModel()
{
	const float dt = ft.mark();
}

void Game::composeFrame()
{
}