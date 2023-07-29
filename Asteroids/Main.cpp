#include "Game.h"

int main()
{
    // Create window.
    const int width = Game::screenWidth;
    const int height = Game::screenHeight;
    sf::RenderWindow window(sf::VideoMode(width, height), "Asteroids");

    // Set framerate limit.
    const int framerateLimit = 0;
    window.setFramerateLimit(framerateLimit);

    // Construct game with reference to the newly-created window.
    // Game will handle event processing and rendering.
    Game game(window);
    while (window.isOpen())
        game.run();

    return 0;
}