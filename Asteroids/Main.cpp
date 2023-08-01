#include "Game.h"
#include "RamWindow.h"

int main()
{
    // Create window.
    const int width = RamWindow::screenWidth;
    const int height = RamWindow::screenHeight;
    sf::RenderWindow window(sf::VideoMode(width, height), "Asteroids");

    // Set framerate limit.
    const int framerateLimit = 0;
    window.setFramerateLimit(framerateLimit);

    window.setKeyRepeatEnabled(false);

    // Construct game with reference to the newly-created window.
    // Game will handle event processing and rendering.
    Game game(window);
    while (window.isOpen())
        game.run();

    return 0;
}