#pragma once

#include <SFML/Graphics.hpp>
#include "FrameTimer.h"

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
public:
	static constexpr int screenWidth = 800;
	static constexpr int screenHeight = 600;
private:
	sf::RenderWindow& rw;
	FrameTimer ft;
	/* ---- Game Variables ---- */
};