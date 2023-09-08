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
	void doBulletAsteroidColl();
	void doPlayerAsteroidColl();
private:
	sf::RenderWindow& rw;
	FrameTimer ft;
	/* ---- Game Variables ---- */
	Ship ship;
	std::vector<Bullet> bullets;
	std::vector<Asteroid> asteroids;
	static constexpr float asteroidSpawnTime = 5.0f;
	float elapsedTime = 0.0f;
	bool gameIsOver = false;
	sf::Font font;
	sf::Text text = { "GAME OVER", font, 80 };
};