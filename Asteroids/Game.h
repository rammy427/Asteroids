#pragma once

#include "FrameTimer.h"
#include "Ship.h"
#include "Bullet.h"
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
private:
	sf::RenderWindow& rw;
	FrameTimer ft;
	/* ---- Game Variables ---- */
	Ship ship;
	std::vector<Bullet> bullets;
};