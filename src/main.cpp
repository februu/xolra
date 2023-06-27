#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

#include "../include/AssetManager.hpp"
#include "../include/SceneManager.hpp"
#include "../include/splashScreenScene.hpp"

int main()
{
    srand(time(NULL));
    sf::RenderWindow window(sf::VideoMode(1600, 900), "xolra");
    sf::Clock clock;
    AssetManager am;
    SceneManager sm;

    // load all the textures
    am.loadTextures();

    SplashScreenScene *splashScreenScene = new SplashScreenScene(&window, &am, &sm);
    sm.changeScene(splashScreenScene);

    // run the program as long as the window is open
    while (window.isOpen())
    {

        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;
        while (window.pollEvent(event))
        {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed)
            {
                sm.changeScene(nullptr);
                window.close();
                return 0;
            }

            if (event.type == sf::Event::Resized)
            {
                // update the view to the new size of the window
                sf::FloatRect visibleArea(0, 0, event.size.width, event.size.height);
                window.setView(sf::View(visibleArea));
            }
        }

        float deltaTime = clock.restart().asSeconds();
        sm.updateCurrentScene(deltaTime);
        sm.drawCurrentScene();
    }

    return 0;
}

// TODO:
// https://github.com/SFML/SFML/wiki/Source%3A-Letterbox-effect-using-a-view