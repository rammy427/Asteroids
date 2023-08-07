#pragma once

#include "FrameTimer.h"
#include "Ship.h"
#include "Bullet.h"
#include "Asteroid.h"
#include <vector>

class Game
{
public:
	Game(sf::RenderWindow& rw);
	void run();
private:
	void processEvents();
	void updateModel();
	void composeFrame();
	/* ---- Game Functions ---- */
	void eraseLostBullets();
private:
	sf::RenderWindow& rw;
	FrameTimer ft;
	/* ---- Game Variables ---- */
	Ship ship;
	std::vector<Bullet> bullets;
	std::vector<Asteroid> asteroids;
};